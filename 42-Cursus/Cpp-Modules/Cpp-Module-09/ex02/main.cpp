#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <ctime>
#include <iomanip>

int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cerr << "Error" << std::endl;
		return (1);
	}

	PmergeMe sorter;
	if (!sorter.parseInput(ac, av))
		return (1);
	sorter.displayBefore();

	clock_t startVec = clock();
	sorter.fordJohnsonSortVector();
	clock_t endVec = clock();
	double timeVec = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1000000;

	clock_t startDeq = clock();
	sorter.fordJohnsonSortDeque();
	clock_t endDeq = clock();
	double timeDeq = static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC * 1000000;

	sorter.displayAfter();
	std::cout << "Time to process a range of " << (ac - 1) 
			  << " elements with std::vector : " << std::fixed << std::setprecision(5) 
			  << timeVec << " us" << std::endl;
	std::cout << "Time to process a range of " << (ac - 1) 
			  << " elements with std::deque  : " << std::fixed << std::setprecision(5) 
			  << timeDeq << " us" << std::endl;

	return (0);
}
