#include "Span.hpp"

Span::Span()
{
	(DEBUG) && std::cout << "Span default constructor invoked !" << std::endl;
	N = 0;
}

Span::Span(unsigned int n)
{
	(DEBUG) && std::cout << "Span param constructor invoked !" << std::endl;
	N = n;
}

Span::Span(const Span & right)
{
	(DEBUG) && std::cout << "Span copy constructor invoked !" << std::endl;
	*this = right;
}

Span & Span::operator=(const Span & right)
{
	(DEBUG) && std::cout << "Span copy assignment operator invoked !" << std::endl;
	if (this != &right)
	{
		this->N = right.N;
		this->vect = right.vect;
	}
	return *this;
}

Span::~Span()
{
	(DEBUG) && std::cout << "Span Destructor invoked !" << std::endl;
}

void	Span::addNumber(int nb)
{
	if (vect.size() >= N)
		throw std::runtime_error("Full!!");
	vect.push_back(nb);
}

int Span::shortestSpan() const
{
	if (vect.size() < 2)
		throw std::runtime_error("vect.size() < 2 !");

	std::vector<int> tmp = vect;
	std::sort(tmp.begin(), tmp.end());

	int mins = tmp[1] - tmp[0];
	for (size_t i = 1; i < tmp.size() - 1; i++)
	{
		int diff = tmp[i + 1] - tmp[i];
		if (diff < mins)
			mins = diff;
	}
	return mins;
}

int Span::longestSpan() const
{
	if (vect.size() < 2)
		throw std::runtime_error("vect.size() < 2 !");

	int min = *std::min_element(vect.begin(), vect.end());
	int max = *std::max_element(vect.begin(), vect.end());
	return (max - min);
}