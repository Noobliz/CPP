#include <iostream>
#include "Array.hpp"
#include <ctime>
#include <cstdlib>


int main (void)
{
    std::cout<<"-----[test operator= and deep memory allocation]----\n";

    Array<std::string> a;
    Array<std::string> b(3);
    b[0] = "blabla";
    b[1] = "more blabla";
    b[2] = "ending blabla";

    a = b;

    std::cout<<"array a at index 1 : "<<a[1]<<std::endl;

    b[1] = "something different";

    std::cout<<"after change, array b at index 1 : "<<b[1]<<std::endl;
    std::cout<<"array a at index 1 : "<<a[1]<<std::endl;

    std::cout<<"\n-----[test index out of range]----\n";

    try{
        b[-42] = "hfhfhf";
    }
    catch(std::exception &e)
    {
        std::cerr<<e.what();
    }

    std::cout<<"\n\n-----[test copy + different type]----\n";

    Array<int> x(4);
    for (int i = 0; i < 4; i++)
        x[i] = i+1;
    
    Array<int> y(x);

    std::cout<<"content of y (copy of x): ";
    for (int i = 0; i < 4; i++)
        std::cout<<y[i]<<" ";
    std::cout<<std::endl;

    return 0;
}



// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//         //std::cout<<mirror[i]<<std::endl;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//         std::cout<<test[2]<<std::endl;
//         std::cout<<tmp[2]<<std::endl;
//         std::cout<<numbers[2]<<std::endl;


//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     std::cout<<mirror[2]<<std::endl;
//     std::cout<<numbers[2]<<std::endl;
//     delete [] mirror;//
//     return 0;
// }