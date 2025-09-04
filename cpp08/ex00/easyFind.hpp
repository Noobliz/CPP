#pragma once
#include <algorithm>


class objectNotFoundException : public std::exception {
    const char* what() const throw() {
        return "Object not found";
    }
};


//std::find : Returns an iterator to the first element in the range [first,last) that compares equal to val.
//If no such element is found, the function returns last.
template <typename T>
int easyFind(T &container, int toFind)
{
    typename T::iterator it = std::find(container.begin(), container.end(), toFind);
    if (it == container.end())
        throw objectNotFoundException();
    return *it;
}