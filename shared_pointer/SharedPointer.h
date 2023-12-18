#pragma once

#include <iostream>

template <class T>
class SharedPointer {
public:
    SharedPointer(): _ptr(nullptr), _cnt(new size_t (0)) {

    };

    SharedPointer(T* ptr): _ptr(ptr), _cnt(new size_t(1)) {

    };

    ~SharedPointer() {

        if (_ptr == nullptr) {
            assert(_cnt == nullptr);
            return;
        }

        if (*_cnt > 0) {
            --(*_cnt);
            return;
        }

        delete _ptr;
        delete _cnt;
    }

    // copy constructor
    SharedPointer(const SharedPointer& other) {

        if (this == &other) {
            return;
        }

        if (other._ptr == nullptr) {
            throw std::runtime_error("[Error] Other has empty pointer");
        }

        _ptr = other._ptr;
        _cnt = other._cnt;
        ++(*_cnt);
    }

    // copy assignment
    SharedPointer& operator=(const SharedPointer& other) {

        _ptr = other._ptr;
        _cnt = other._cnt;
        ++(*_cnt);
        return *this;
    }

    // move constructor
    SharedPointer(SharedPointer&& other): _ptr(other._ptr), _cnt(other._cnt) {

        other._ptr = nullptr;
        other._cnt = nullptr;
    }

    // move assignment
    SharedPointer& operator=(SharedPointer&& other) {
       _ptr = other._ptr;
       _cnt = other._cnt;
       other._ptr = nullptr;
       other._cnt = nullptr;

       return *this;
    }

    size_t getCounter() const {
        return(*_cnt);
    }

    T& getData() const {
        return *_ptr;
    }

    T* getPointer() const {
        return _ptr;
    }

private:
    T* _ptr{nullptr};
    size_t* _cnt{nullptr};
};