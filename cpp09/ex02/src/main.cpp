
#include "../inc/PmergeMe.hpp"


int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr<<"Error: input numbers"<<std::endl;
        return (1);
    }
    PmergeMe p;
    if (!p.storeNb(argv, argc))
        return (1);
    p.sort();
}