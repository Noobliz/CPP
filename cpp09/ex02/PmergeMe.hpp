#pragma once
# include <iostream>
# include <vector>
# include <stack>
# include <sstream>
# include <cstdio>

class PmergeMe
{
    private:
        std::vector<int>    _vector;
        std::deque<int>     _deque;
    
    public:
        PmergeMe();
        bool storeNb(char **argv, int argc);
        void sort();
        void sortVector(std::vector<int> &v);
};