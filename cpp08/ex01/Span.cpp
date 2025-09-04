#include "Span.hpp"
#include <stdexcept>
#include <algorithm>
#include <numeric>
# include <limits>
#include <climits>

Span::Span(unsigned int n): _capacity(n){
    _v.reserve(n);//reserve n capacity in the vector (allocate n space)
}

Span::Span(const Span &copy): _capacity(copy._capacity), _v(copy._v)
{
   // _v.reserve(copy._capacity); should I ?
}
Span& Span::operator=(const Span &other){
    if (this != &other)
    {
        _capacity = other._capacity;
        _v = other._v; //works because vector has it's own operator= deep copy
        //_v.reserve(_capacity);
    }
    return (*this);
}

Span::~Span()
{
    //no need to delete, vector does it itself
}

void    Span::addNumber(unsigned int n)
{
    if(_v.size() >= _capacity)
        throw std::out_of_range("vector is full\n");
    _v.push_back(n);
}



//std::adjacent_difference(first, last, result): calculate diff between
//consecutive elements and writes them in "result". 
// /!!\ result[0] is the first element of the previous array, not the diff so you need to jump it.
int Span::shortestSpan()const{
    if(_v.empty())
        throw spanException("vector is empty\n");
    if(_v.size() == 1)
        throw spanException("no span can be found\n");
    std::vector<int> sorted = _v;
    std::sort(sorted.begin(), sorted.end());

    std::vector<int> diff(sorted.size());//vector for result(adj_diff)
    std::adjacent_difference(sorted.begin(), sorted.end(), diff.begin());

    int result = INT_MAX;
    for (unsigned int i = 1; i < diff.size(); i++)
            result = std::min(result, diff[i]);
    return result;
}


int Span::longestSpan()const{
    if(_v.empty())
        throw spanException("vector is empty\n");
    if(_v.size() == 1)
        throw spanException("no span can be found\n");
    std::vector<int> sorted = _v;
    std::sort(sorted.begin(), sorted.end());
    return (sorted.back() - sorted.front());
}




//error msg exception

Span::spanException::spanException(const std::string &msg): _msg(msg){}

const char* Span::spanException::what()const throw()
{
    return _msg.c_str();
}
Span::spanException::~spanException()throw(){}