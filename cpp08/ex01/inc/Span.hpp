#pragma once
#include <vector>
#include <exception>
#include <iostream>

class Span{
    private:
        unsigned int _capacity;
        std::vector<int> _v;
        Span();
    public:
        Span(unsigned int n);
        Span(const Span &copy);
        ~Span();
        Span& operator=(const Span &other);

        void    addNumber(unsigned int n);
        int shortestSpan()const;
        int longestSpan()const;

        template<typename T>
        void    addRange(T first, T last)
        {
            size_t distance = std::distance(first, last);
            if (_v.size() + distance > _capacity)
                throw spanException("Not enough capacity to add numbers\n");
            _v.insert(_v.end(), first, last);
        }



        //personalized msg exception
        class spanException: public std::exception{
                std::string _msg;
            public:
                spanException(const std::string &msg);
                ~spanException()throw();
                const char* what()const throw();
        };
};