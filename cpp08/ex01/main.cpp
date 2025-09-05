#include "Span.hpp"
#include <ctime>
#include <algorithm>

int main (void)
{
    Span a(4);
    std::cout<<"----[simple test + copy and assignment]----\n\n";
    try{
        a.addNumber(0);
        a.addNumber(1);
        a.addNumber(5);
        a.addNumber(22);
        // a.addNumber(36);
        std::cout<<"shortestSpan of a: "<<a.shortestSpan()<<std::endl;
        std::cout<<"longestSpan of a: "<<a.longestSpan()<<std::endl;
        Span b(a);
        std::cout<<"shortestSpan of b: "<<b.shortestSpan()<<std::endl;
        std::cout<<"longestSpan of b: "<<b.longestSpan()<<std::endl;
        Span c(15);

        c = b;
        std::cout<<"shortestSpan of c: "<<c.shortestSpan()<<std::endl;
        std::cout<<"longestSpan of c: "<<c.longestSpan()<<std::endl;

    }
    catch (std::exception &e)
    {
        std::cerr<<e.what();
    }

    std::cout<<"\n----[adding a big range of numbers]----\n\n";

    try{

        std::vector<int> range(10000);
        std::generate(range.begin(), range.end(), rand);
        Span big(10001);
        big.addRange(range.begin(), range.end());
        std::cout<<"shortestSpan of big: "<<big.shortestSpan()<<std::endl;
        std::cout<<"longestSpan of big: "<<big.longestSpan()<<std::endl;
    }
    catch(std::exception &e)
    {
        std::cerr<<e.what();
    }


    std::cout<<"\n----[adding range of numbers from a different type of container]----\n\n";

    try{
        int arr[500];
        for (int i = 0; i < 500; i++)
            arr[i] = i + 1;
        Span fromArr(501);
        fromArr.addRange(arr, arr + 500);
        std::cout<<"shortestSpan of fromArr: "<<fromArr.shortestSpan()<<std::endl;
        std::cout<<"longestSpan of fromArr: "<<fromArr.longestSpan()<<std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr<<e.what();
    }

    return 0;
}