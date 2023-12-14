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

    explicit Vector(size_type n, const T & val = T()): _data(nullptr), _cap(n), _size(n) {
        _data = _alloc.allocate(n);
        std::uninitialized_fill(_data, _data + _cap, val);  // fill the vector with the same value
    }

    reference operator[](size_type i) {
        // index without checking: write vector through i

        return _data[i];
    }

    const_reference operator[](size_type i) const {
        // index without checking: read vector through i

        return _data[i];
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