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

void PmergeMe::sortVector(std::vector<int> &v)
{
    if (v.size() == 2)
    {
        if (v[0] > v[1])
            std::swap(v[0], v[1]);
        return ;
    }

    std::vector<int> big;
    std::vector<int> small;
    for (size_t i = 0; i < v.size(); ++i)
    {
        size_t next = i + 1;
        if (next == v.size())
            big.push_back(v[i]);
        else
        {
            if (v[i] >= v[next])
            {
                big.push_back(v[i]);
                small.push_back(v[next]);
            }
            else
            {
                big.push_back(v[next]);
                small.push_back(v[i]);
            }
            ++i;
        }
    }
    sortVector(big);

    std::cout<<"big: ";   
    for (size_t i = 0; i < big.size(); ++i)
        std::cout<<big[i]<<" ";
    std::cout<<std::endl;
    
    std::cout<<"small: ";   
    for (size_t i = 0; i < small.size(); ++i)
        std::cout<<small[i]<<" ";
    std::cout<<std::endl;
    

    for (size_t i = 0; i < small.size(); ++i)
    {
        std::vector<int>::iterator it = std::lower_bound(big.begin(), big.end(), small[i]);
        big.insert(it, small[i]);
    }
    std::cout<<"big after insertion: ";   
    for (size_t i = 0; i < big.size(); ++i)
        std::cout<<big[i]<<" ";
    std::cout<<std::endl;

    v = big;
}



void PmergeMe::sort()
{
    sortVector(_vector);

    std::cout<<"_vector sorted: ";   
    for (size_t i = 0; i < _vector.size(); ++i)
        std::cout<<_vector[i]<<" ";
    std::cout<<std::endl;

}