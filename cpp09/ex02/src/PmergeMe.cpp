#include "../inc/PmergeMe.hpp"
#include <algorithm>
#include <ctime>

PmergeMe::PmergeMe(){
    int suite[] = {
        0, 1, 3, 5, 11, 21, 43, 85, 171, 
        341, 683, 1365, 2731
    };

    for (size_t i = 0; i < 13; ++i)
        _JacobSuite.push_back(suite[i]);
}

PmergeMe::PmergeMe(const PmergeMe &copy)
{
    *this = copy;
}

PmergeMe& PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        _vector = other._vector;
        _deque = other._deque;
        _JacobSuite = other._JacobSuite;
    }
    return *this;
}

PmergeMe::~PmergeMe(){}






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
    if (_vector.size() < 2)
    {
        std::cerr<<"input at least 2 numbers"<<std::endl;
        return false;
    }
    return true;
}


void PmergeMe::sortVector(std::vector<int> &v)
{
    if (v.size() <= 2)
    {
        if (v.size() <= 1)
            return ;
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
    
    // std::cout<<"big: ";   
    // for (size_t i = 0; i < big.size(); ++i)
    // std::cout<<big[i]<<" ";
    // std::cout<<std::endl;
    
    // std::cout<<"small: ";   
    // for (size_t i = 0; i < small.size(); ++i)
    // std::cout<<small[i]<<" ";
    // std::cout<<std::endl;
    
    sortVector(big);
    //==================================|JACOB|========================================================


    std::vector<int> indexToInsert;
    for (size_t i = 0; i < _JacobSuite.size(); ++i)
    {
        int index = _JacobSuite[i];
        if (index < static_cast<int>(small.size()))
            indexToInsert.push_back(index);
    }


    for (size_t i = 0; i < small.size(); ++i)
    {
        std::vector<int>::iterator it;
        int idx = i;
        it = std::find(indexToInsert.begin(), indexToInsert.end(), idx);
        if (it == indexToInsert.end())
            indexToInsert.push_back(idx);
    }

    //=================================================|INSERT|============================================

    for (size_t i = 0; i < small.size(); ++i)
    {
        std::vector<int>::iterator it = std::lower_bound(big.begin(), big.end(), small[indexToInsert[i]]);
        big.insert(it, small[indexToInsert[i]]);
    }

    v = big;
}

void PmergeMe::sortDeque(std::deque<int> &d)
{
    if (d.size() <= 2)
    {
        if(d.size() <= 1)
            return ;
        if(d[0] > d[1])
            std::swap(d[0], d[1]);
    }
    std::deque<int> big;
    std::deque<int> small;
    for (size_t i = 0; i < d.size(); ++i)
    {
        size_t next = i + 1;
        if (next == d.size())
            big.push_back(d[i]);
        else
        {
            if (d[i] >= d[next])
            {
                big.push_back(d[i]);
                small.push_back(d[next]);
            }
            else
            {
                big.push_back(d[next]);
                small.push_back(d[i]);
            }
            ++i;
        }
    }
    
    sortDeque(big);

    //======building indextoInsert======================
    std::vector<int> indexToInsert;
    for (size_t i = 0; i < _JacobSuite.size(); ++i)
    {
        int index = _JacobSuite[i];
        if (index < static_cast<int>(small.size()))
            indexToInsert.push_back(index);
    }

    for (size_t i = 0; i < small.size(); ++i)
    {
        std::vector<int>::iterator it;
        int idx = i;
        it = std::find(indexToInsert.begin(), indexToInsert.end(), idx);
        if (it == indexToInsert.end())
            indexToInsert.push_back(idx);
    }
    //=============insertion====================

    for (size_t i = 0; i < small.size(); ++i)
    {
        std::deque<int>::iterator it = std::lower_bound(big.begin(), big.end(), small[indexToInsert[i]]);
        big.insert(it, small[indexToInsert[i]]);
    }
    d = big;
}


void PmergeMe::sort()
{
    
    std::cout<<"Before : ";   
    for (size_t i = 0; i < _vector.size(); ++i)
    std::cout<<_vector[i]<<" ";
    std::cout<<std::endl;
    
    clock_t vStart = clock();
    sortVector(_vector);
    clock_t vEnd = clock();

    clock_t dStart = clock();
    sortDeque(_deque);
    clock_t dEnd = clock();
    
    std::cout<<"After : "; 
    for (size_t i = 0; i < _vector.size(); ++i)
        std::cout<<_vector[i]<<" ";
    std::cout<<std::endl;

    //====display time=====
    double time = static_cast<double>(vEnd - vStart) / CLOCKS_PER_SEC;
    std::cout<<"Time to process a range of "<<_vector.size()
        <<" elements with std::vector : "<<time<<" s"<<std::endl;
    time = static_cast<double>(dEnd - dStart) / CLOCKS_PER_SEC;

    std::cout<<"Time to process a range of "<<_deque.size()
        <<" elements with std::deque : "<<time<<" s"<<std::endl;
}