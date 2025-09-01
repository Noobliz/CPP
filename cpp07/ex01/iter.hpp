#pragma once

#include <iostream>

//passing a template for the function to be able to handle different params(const and non const)
template <typename T, typename F>
void iter(T *array, size_t length, F function){
    if (!array)
        return ;
    for (size_t i = 0; i < length; i++)
        function(array[i]);
}

template <typename T>
void display(T const &x)
{
    std::cout<<x<<" ";
}
template<typename T>
void addOne(T &x)
{
    x++;
}

