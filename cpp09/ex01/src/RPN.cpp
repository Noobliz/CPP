#include "../inc/RPN.hpp"

static bool doOperation(std::stack<double> &stack, char ope)
{
    if (stack.size() < 2)
        return false;
    double b = stack.top();
    stack.pop();
    double a = stack.top();
    stack.pop();
    
    double res;

    switch(ope)
    {
        case '/':
            if (b == 0)
            {
                std::cerr<<"division by 0"<<std::endl;
                return false;
            }
            res = a / b;
            break;
        case '+': res = a + b; break;
        case '-': res = a - b; break;
        case '*': res = a *b; break;
        default:
            return false;
    }
    stack.push(res);
    return true;

}

void    RPN(const std::string &values)
{
    std::stack<double> stack;
    
    for (size_t i = 0; i < values.length(); ++i)
    {
        if (values[i] == ' ')
            continue;
        if(isdigit(values[i]))
        {
            if ((i > 0 && isdigit(values[i - 1])) || (i < values.length() && isdigit(values[i + 1])))
            {
                std::cerr<<"Error: multi-digits numbers not allowed"<<std::endl;
                return ;
            }
            stack.push(values[i] - '0');
        }
        else if (!(doOperation(stack, values[i])))
        {
            std::cerr<<"Error"<<std::endl;
            return ;
        }
    }
    if (stack.size() == 1)
        std::cout<<stack.top()<<std::endl;
    else
        std::cerr<<"Error"<<std::endl;
}