#pragma once

# include <string>
# include <stack>
#include <iostream>
#include <sstream>
#include <cstdlib>

#ifndef DEBUG
# define DEBUG 0
#endif

class RPN
{
	private:
		std::stack<int> _stack;

	public:
		RPN();
		RPN(RPN const &right);
		RPN &operator=(RPN const &right);
		~RPN();

		void	calculate(std::string const &av1);
		bool	isOperator(std::string const &token) const;
		bool	isNumber(std::string const &token) const;
		int		calc(int n1, int n2, char op) const;
};