#include "RPN.hpp"

RPN::RPN()
{
	(DEBUG) && std::cout << "RPN default constructor invoked!" << std::endl;
}

RPN::RPN(RPN const &right)
{
	(DEBUG) && std::cout << "RPN copy constructor invoked!" << std::endl;
	*this = right;
}

RPN &RPN::operator=(RPN const &right)
{
	(DEBUG) && std::cout << "RPN asseign op invoked!" << std::endl;
	if (this != &right)
		this->_stack = right._stack;
	return (*this);
}
RPN::~RPN()
{
	(DEBUG) && std::cout << "RPN destructor invoked!" << std::endl;
}

bool RPN::isOperator(std::string const &token) const
{
	return (token == "+" || token == "-" || token == "*" || token == "/");
}

bool RPN::isNumber(std::string const &token) const
{
	if (token.empty())
		return (false);

	if (token.length() == 1 && isdigit(token[0]))
		return (true);

	if (token.length() == 2 && token[0] == '-' && isdigit(token[1]))
		return (true);

	return (false);
}

int RPN::calc(int n1, int n2, char op) const
{
	if (op == '+')
		return (n1 + n2);
	else if (op == '-')
		return (n1 - n2);
	else if (op == '*')
		return (n1 * n2);
	else if (op == '/')
	{
		if (n2 == 0)
		{
			std::cerr << "Error: n1 / 0" << std::endl;
			exit(1);
		}
		return (n1 / n2);
	}
	else
	{
		std::cerr << "Error: invalid operator" << std::endl;
		exit(1);
	}
}

void RPN::calculate(std::string const &av1)
{
	std::istringstream iss(av1);
	std::string	token;

	while (iss >> token)
	{
		if (isNumber(token))
		{
			int n = atoi(token.c_str());
			_stack.push(n);
		}
		else if (isOperator(token))
		{
			if (_stack.size() < 2)
			{
				std::cerr << "Error" << std::endl;
				return ;
			}

			int n2 = _stack.top();
			_stack.pop();
			int n1 = _stack.top();
			_stack.pop();

			int res = calc(n1, n2, token[0]);
			_stack.push(res);
		}
		else
		{
			std::cerr << "Error" << std::endl;
			return;
		}
	}

	if (_stack.size() != 1)
	{
		std::cerr << "Error" << std::endl;
		return ;
	}
	std::cout << _stack.top() << std::endl;
}
