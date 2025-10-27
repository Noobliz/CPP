#include "../inc/MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "top is : " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "after pop, size is : " <<mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    std::cout << "mstack contains: "<< std::endl;
    while (it != ite)
    {
        std::cout << *it <<" | ";
        ++it;
    }
    std::cout<<std::endl;
    std::stack<int> s(mstack);

	std::cout << std::endl;
	
	// Test MutantStack
	MutantStack<int> ms;
	ms.push(5);
	ms.push(17);
	ms.push(3);
	ms.push(42);

	std::cout << "MutantStack top: " << ms.top() << std::endl;

	std::cout << "MutantStack contents (begin->end): ";
	for (MutantStack<int>::iterator it = ms.begin(); it != ms.end(); ++it)
		std::cout << *it << ' ';
	std::cout << std::endl;

	std::cout << "MutantStack contents (rbegin->rend): ";
	for (MutantStack<int>::reverse_iterator rit = ms.rbegin(); rit != ms.rend(); ++rit)
		std::cout << *rit << ' ';
	std::cout << std::endl;

	// Pop one element and show top
	ms.pop();
	std::cout << "After pop, MutantStack top: " << ms.top() << std::endl;

		std::cout << "MutantStack contents (rbegin->rend): ";
	for (MutantStack<int>::reverse_iterator rit = ms.rbegin(); rit != ms.rend(); ++rit)
		std::cout << *rit << ' ';
	std::cout << std::endl;
	
	// Compare with std::list filled the same way (push_back)
	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(17);
	lst.push_back(3);
	lst.push_back(42);

	std::cout << "std::list contents (push_back order): ";
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
		std::cout << *it << ' ';
	std::cout << std::endl;
    return 0;
}