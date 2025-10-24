#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}

bool PmergeMe::storeNb(char **argv, int argc)
{
    for(int i = 1; i < argc; ++i)
    {
        std::istringstream iss(argv[i]);
        int num = 0;
        if (!(iss >> num) || num < 0 || iss.peek() != EOF)//only digits
        {
            std::cerr<<"Error"<<std::endl;
            return false;
        }
        _vector.push_back(num);
        _deque.push_back(num);
    }
    for (size_t i = 0; i < _vector.size(); ++i)
        std::cout<<_vector[i]<<" ";
    std::cout<<std::endl;
    return true;
}