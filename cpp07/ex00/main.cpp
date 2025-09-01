#include "template.hpp"
#include "Test.hpp"

int main(void)
{
    std::cout<<"----[with 2 objects of class Test]------\n\n";
    Test x(150);
    Test y(42);
    std::cout<<"between instances x and y the biggest is : "
            <<max(x, y)<<std::endl;

    std::cout<<"\n----[tests from subject]------\n\n";
    int a = 2;
    int b = 3;
    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
}