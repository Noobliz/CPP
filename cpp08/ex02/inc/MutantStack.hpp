#pragma once
# include <stack>

template <typename T>
class MutantStack: public std::stack<T>
{
    public:
        MutantStack();
        MutantStack(const MutantStack &copy);
        MutantStack &operator=(const MutantStack &other);
        ~MutantStack();

        //======aliases for iterators of stack containers======
        typedef typename std::stack<T>::container_type::iterator iterator;//the element can be modified
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;//here not (const)

        typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
        typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

        //=====members==========
        iterator begin();
        iterator end();

        const_iterator begin() const;
        const_iterator end() const;

        
        reverse_iterator rbegin();
        reverse_iterator rend();

        const_reverse_iterator rbegin() const;
        const_reverse_iterator rend() const;
};

#include "../src/MutantStack.tpp"