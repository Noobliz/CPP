#pragma once

#include <iostream>
#include <stdexcept>

template<typename T>
class Array{
    private:
        T *_array;
        unsigned int _size;
    public:
        Array();
        Array(unsigned int n);
        Array(const Array &copy);
        ~Array();
        Array& operator=(const Array &other);

        unsigned int    size()const;

        T& operator[](unsigned int index);

};

#include "Array.tpp"