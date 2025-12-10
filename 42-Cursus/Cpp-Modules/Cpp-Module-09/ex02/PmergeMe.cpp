#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <climits>

PmergeMe::PmergeMe()
{
	(DEBUG) && std::cout << "PmergeMe default constructor invoked!" << std::endl;
}

PmergeMe::PmergeMe(PmergeMe const &src)
{
	(DEBUG) && std::cout << "PmergeMe copy constructor invoked!" << std::endl;
	*this = src;
}

PmergeMe::~PmergeMe()
{
	(DEBUG) && std::cout << "PmergeMe destructor invoked!" << std::endl;
}

PmergeMe &PmergeMe::operator=(PmergeMe const &rhs)
{
	(DEBUG) && std::cout << "PmergeMe = operator invoked!" << std::endl;
	if (this != &rhs)
	{
		this->_vec = rhs._vec;
		this->_deq = rhs._deq;
	}
	return (*this);
}

bool PmergeMe::parseInput(int ac, char **av)
{
	for (int i = 1; i < ac; i++)
	{
		std::string arg = av[i];
		if (arg.empty())
		{
			std::cerr << "Error" << std::endl;
			return (false);
		}
		for (size_t j = 0; j < arg.length(); j++)
		{
			if (!isdigit(arg[j]))
			{
				std::cerr << "Error" << std::endl;
				return (false);
			}
		}
		char *endptr;
		long num = strtol(arg.c_str(), &endptr, 10);
		if (*endptr != '\0' || num < 0 || num > INT_MAX)
		{
			std::cerr << "Error" << std::endl;
			return (false);
		}
		_vec.push_back(static_cast<int>(num));
		_deq.push_back(static_cast<int>(num));
	}
	return (true);
}

void PmergeMe::displayBefore() const
{
	std::cout << "Before: ";
	for (size_t i = 0; i < _vec.size(); i++)
	{
		std::cout << _vec[i];
		if (i < _vec.size() - 1)
			std::cout << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::displayAfter() const
{
	std::cout << "After:  ";
	for (size_t i = 0; i < _vec.size(); i++)
	{
		std::cout << _vec[i];
		if (i < _vec.size() - 1)
			std::cout << " ";
	}
	std::cout << std::endl;
}

std::vector<int>& PmergeMe::getVector()
{
	return _vec;
}

std::deque<int>& PmergeMe::getDeque()
{
	return _deq;
}

void PmergeMe::pairAndSplitVector(std::vector<int> &larger, std::vector<int> &smaller, int &unpaired)
{
	size_t n = _vec.size();
	
	unpaired = -1;
	larger.clear();
	smaller.clear();

	std::vector<std::pair<int, int> > pairs;
	for (size_t i = 0; i + 1 < n; i += 2)
	{
		if (_vec[i] > _vec[i + 1])
			pairs.push_back(std::make_pair(_vec[i], _vec[i + 1]));
		else
			pairs.push_back(std::make_pair(_vec[i + 1], _vec[i]));
	}

	if (n % 2 == 1)
		unpaired = _vec[n - 1];
	for (size_t i = 0; i < pairs.size(); i++)
		larger.push_back(pairs[i].first);
	if (larger.size() > 1)
		mergeSortVector(larger, 0, larger.size() - 1);
	smaller.clear();
	for (size_t i = 0; i < larger.size(); i++)
	{
		for (size_t j = 0; j < pairs.size(); j++)
		{
			if (pairs[j].first == larger[i])
			{
				smaller.push_back(pairs[j].second);
				break;
			}
		}
	}
}

void PmergeMe::pairAndSplitDeque(std::deque<int> &larger, std::deque<int> &smaller, int &unpaired)
{
	size_t n = _deq.size();
	unpaired = -1;

	larger.clear();
	smaller.clear();

	std::vector<std::pair<int, int> > pairs;
	
	for (size_t i = 0; i + 1 < n; i += 2)
	{
		if (_deq[i] > _deq[i + 1])
			pairs.push_back(std::make_pair(_deq[i], _deq[i + 1]));
		else
			pairs.push_back(std::make_pair(_deq[i + 1], _deq[i]));
	}
	if (n % 2 == 1)
		unpaired = _deq[n - 1];
	

	for (size_t i = 0; i < pairs.size(); i++)
		larger.push_back(pairs[i].first);
	
	if (larger.size() > 1)
		mergeSortDeque(larger, 0, larger.size() - 1);
	
	smaller.clear();
	for (size_t i = 0; i < larger.size(); i++)
	{
		for (size_t j = 0; j < pairs.size(); j++)
		{
			if (pairs[j].first == larger[i])
			{
				smaller.push_back(pairs[j].second);
				break;
			}
		}
	}
}

int PmergeMe::binarySearchVector(std::vector<int> &arr, int value, int end)
{
	int left = 0;
	int right = end;
	
	while (left < right)
	{
		int mid = left + (right - left) / 2;
		if (arr[mid] < value)
			left = mid + 1;
		else
			right = mid;
	}
	return left;
}

int PmergeMe::binarySearchDeque(std::deque<int> &arr, int value, int end)
{
	int left = 0;
	int right = end;
	
	while (left < right)
	{
		int mid = left + (right - left) / 2;
		if (arr[mid] < value)
			left = mid + 1;
		else
			right = mid;
	}
	return left;
}

void PmergeMe::fordJohnsonSortVector()
{
	if (_vec.size() <= 1)
		return;
	std::vector<int> larger, smaller;
	int		unpaired;

	pairAndSplitVector(larger, smaller, unpaired);
	
	std::vector<int> mainChain;
	
	if (!smaller.empty())
		mainChain.push_back(smaller[0]);
	
	for (size_t i = 0; i < larger.size(); i++)
		mainChain.push_back(larger[i]);
	
	for (size_t i = 1; i < smaller.size(); i++)
	{
		int pos = binarySearchVector(mainChain, smaller[i], mainChain.size());
		mainChain.insert(mainChain.begin() + pos, smaller[i]);
	}
	
	if (unpaired != -1)
	{
		int pos = binarySearchVector(mainChain, unpaired, mainChain.size());
		mainChain.insert(mainChain.begin() + pos, unpaired);
	}
	_vec = mainChain;
}

void PmergeMe::fordJohnsonSortDeque()
{
	if (_deq.size() <= 1)
		return;
	
	std::deque<int> larger, smaller;
	int unpaired;
	
	pairAndSplitDeque(larger, smaller, unpaired);
	
	std::deque<int> mainChain;
	
	if (!smaller.empty())
		mainChain.push_back(smaller[0]);
	
	for (size_t i = 0; i < larger.size(); i++)
		mainChain.push_back(larger[i]);

	for (size_t i = 1; i < smaller.size(); i++)
	{
		int pos = binarySearchDeque(mainChain, smaller[i], mainChain.size());
		mainChain.insert(mainChain.begin() + pos, smaller[i]);
	}
	if (unpaired != -1)
	{
		int pos = binarySearchDeque(mainChain, unpaired, mainChain.size());
		mainChain.insert(mainChain.begin() + pos, unpaired);
	}
	
	_deq = mainChain;
}
