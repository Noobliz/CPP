#include "Array.hpp"

template <typename T>
Array<T>::Array():_array(NULL), _size(0){}


template <typename T>
Array<T>::Array(unsigned int n): _array(new T[n]()), _size(n){
}

template <typename T>
Array<T>::Array(const Array &copy):_array(NULL), _size(0)
{
    *this = copy; //deep copy because operator= is called
}

template <typename T>
Array<T>::~Array()
{
    delete[] _array;
}
template <typename T>
Array<T>& Array<T>::operator=(const Array &other)
{
    if (this != &other)
    {
        if (_array)
            delete[] _array;
        _size = other._size;
        _array = new T[_size];
        for (size_t i = 0; i < _size; i++)
            _array[i] = other._array[i];
    }
    return (*this);
}


template <typename T>
unsigned int Array<T>::size()const
{
    return _size;
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
    if (index >= _size)//if index negative, casted in unsigned int become massive value
        throw std::out_of_range("index out of limits");
    return (_array[index]);
}