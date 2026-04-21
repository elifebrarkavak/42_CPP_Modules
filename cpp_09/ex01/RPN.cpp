#include "RPN.hpp"

RPN::RPN()
{

}

RPN::~RPN()
{

}

RPN::RPN(const RPN& other)
{
    *this = other;
}

RPN& RPN::operator=(const RPN& other)
{
    if (this != &other)
        this->_stack = other._stack;
    return *this;
}

void RPN::calculate(const std::string& argv)
{
    for (size_t i = 0; i < argv.length(); ++i)
    {
        char c = argv[i];

        if (c == ' ')
            continue ;

        if (std::isdigit(c))
        {
            int d = c - '0';
            _stack.push(d);
        } 
        else if (c == '+' || c == '-' || c == '*' || c == '/')
        {
            if (_stack.size() < 2)
            {
                std::cerr << "ERROR!! Not enough operands " << std::endl;
                return ;
            }

            int res = 0;
            int b = _stack.top();
            _stack.pop();
            int a = _stack.top();
            _stack.pop();

            if (c == '+')
            {
                res = a + b;
                _stack.push(res);
            }
            else if (c == '-') 
            {
                res = a - b;
                _stack.push(res);
            }
            else if (c == '*') 
            {
                res = a * b;
                _stack.push(res);
            }
            else if (c == '/')
            {
                if (b == 0)
                {
                    std::cerr << "ERROR!! Division by zero!!" << std::endl;
                    return ;
                }
                res = a / b;
                _stack.push(res);
            }
        } 
        else
        {
            std::cerr << "ERROR!! Invalid character"<< std::endl;
            return ;
        }
    }
    if (_stack.size() != 1)
    {
        std::cerr << "ERROR!! The argv is incomplete" << std::endl;
    }
    else
    {
        std::cout << _stack.top() << std::endl;
    }
}
