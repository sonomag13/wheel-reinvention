#pragma once

#include <iostream>

template<typename T>
class Vector {
public:
    // we use these typedefs for the sake of convention
    typedef T* iterator;
    typedef const T* const_iterator;
    typedef size_t size_type;
    typedef std::ptrdiff_t difference_type;
    typedef T value_type;
    typedef T& reference;
    typedef const T& const_reference;

    Vector(): _data(nullptr), _cap(0), _size(0) {

    };

    explicit Vector(size_type n, const_reference val = T()): _cap(n), _size(n), _data(nullptr) {
        // fill the vector with the same value

        _data = _alloc.allocate(_cap);
        std::uninitialized_fill(_data, _data + _cap, val);
    }

    Vector(const Vector<T> & otherVec): _cap(otherVec._cap), _size(otherVec._size), _data(nullptr) {
        // copy constructor

        _data = _alloc.allocate(_cap);
        std::uninitialized_copy(otherVec._data, otherVec._data + otherVec._size, _data);
    }

    reference operator[](size_type i) {
        // index without checking: write vector through i

        return _data[i];
    }

    const_reference operator[](size_type i) const {
        // index without checking: read vector through i

        return _data[i];
    }

    reference operator=(const_reference otherVec) {
        // copy assignment

        if (_data != nullptr) {
            delete[] _data;
        }

        _cap = otherVec._cap;
        _size = otherVec._size;
        _data = otherVec._data;

        return *this;
    }

    // begin and end iterator
    iterator begin() {
        return _data;
    }

    const_iterator begin() const{
        return _data;
    }

    iterator end() {
        return _data + _size;
    }

    const_iterator end() const{
        return _data + _size;
    }

    void push_back(const_reference val) {
        // push a value to the back of the vector

        if (_data == nullptr) {
            _data = _alloc.allocate(1);
            _cap = 1;
        }

        if (_size == _cap) {
            _cap *= 2;  // double the capability
            T* tmp{_alloc.allocate(_cap)};
            memcpy(tmp, _data, _size * sizeof(value_type));
            _data = tmp;
        }

        _data[_size] = val;
        _size++;
    }

    reference at(size_type i) {
        // index with checking: write vector through i

        if (i < 0 || i >= _cap) {
            throw std::out_of_range("[Error] Out of boundary error");
        }

        return _data[i];
    }

    const_reference at(size_type i) const {
        // index with checking: read vector through i

        if (i < 0 || i >= _cap) {
            throw std::out_of_range("[Error] Out of boundary error");
        }

        return _data[i];
    }

    ~Vector() {
        if (_data) {
            delete[] _data;
        }
        _data = nullptr;
        _cap = _size = 0;
    }

    size_type size() const {
        // return the size of the vector

        return _size;
    }

private:
    iterator _data;  // first element
    size_type _cap;  // one past the last element allocated
    size_type _size;  // one past the last element

    std::allocator<T> _alloc;

};