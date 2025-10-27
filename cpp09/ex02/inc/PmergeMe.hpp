#pragma once
# include <iostream>
# include <vector>
# include <deque>
# include <sstream>
# include <cstdio>

class PmergeMe
{
    private:
        std::vector<int>    _vector;
        std::deque<int>     _deque;//memory is not contiguous

        std::vector<int>    _JacobSuite;
    
    public:
        PmergeMe();
        PmergeMe(const PmergeMe &copy);
        PmergeMe& operator=(const PmergeMe &other);
        ~PmergeMe();

        
        bool storeNb(char **argv, int argc);
        void sort();
        void sortVector(std::vector<int> &v);
        void sortDeque(std::deque<int> &d); 

        
};