#include "iter.hpp"

int main(void)
{
    std::cout<<"---[Test with array of int]---\n";
    int array[]= {1, 2, 3, 4, 5};
    size_t length1 = sizeof(array) / sizeof(array[0]);
    
    iter(array, length1, display<int>);
    std::cout<<std::endl;
    iter(array, length1, addOne<int>);
    std::cout<<"after addOne:\n";
    iter(array, length1, display<int>);


    std::cout<<"\n---[Test with array of chars]---\n";
    char arrayChar[] = {'a', 'b', 'c'};
    iter(arrayChar, 3, display<char>);
    std::cout<<std::endl;
    iter(arrayChar, 3, addOne<char>);
    std::cout<<"after addOne:\n";
    iter(arrayChar, 3, display<char>);


    std::cout<<"\n---[Test with array of strings]---\n";
    const std::string& test= "hamster";
    std::string const arrayString[] = {test, "beaver"};
    size_t length2 = sizeof(arrayString) / sizeof(arrayString[0]);
    
    iter(arrayString, length2, display<std::string>);
    std::cout<<std::endl;

    return 0;
}

