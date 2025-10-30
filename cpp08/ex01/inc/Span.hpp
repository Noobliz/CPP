#pragma once
#include <vector>
#include <exception>
#include <iostream>

class Span{
    private:
        unsigned int _capacity;
        std::vector<int> _v;
    public:
        Span();
        Span(unsigned int n);
        Span(const Span &copy);
        ~Span();
        Span& operator=(const Span &other);

        void    addNumber(unsigned int n);
        int shortestSpan()const;
        int longestSpan()const;

        void    addRange(std::vector<int>::iterator first, std::vector<int>::iterator last);


        //personalized msg exception
        class spanException: public std::exception{
                std::string _msg;
            public:
                spanException(const std::string &msg);
                ~spanException()throw();
                const char* what()const throw();
        };
};