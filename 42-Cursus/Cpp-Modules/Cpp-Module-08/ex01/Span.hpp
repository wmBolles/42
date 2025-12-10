#pragma once

#include <stdexcept>
#include <vector>
#include <iostream>
#include <algorithm>

#ifndef DEBUG
#define  DEBUG 0
#endif

class Span
{
	private:
		unsigned int		 N;
		std::vector<int>	vect;

	public:
		Span();
		Span(unsigned int n);
		Span(const Span & right);
		Span & operator=(const Span & right);
		~Span();

		void	addNumber(int nb);

		template <typename It>
		void addRange(It begin, It end)
		{
			if (vect.size() + std::distance(begin, end) > N)
				throw std::runtime_error("distance > size soo noo space !!");
			vect.insert(vect.end(), begin, end);
		}

		int		shortestSpan() const;
		int 	longestSpan() const;
};
