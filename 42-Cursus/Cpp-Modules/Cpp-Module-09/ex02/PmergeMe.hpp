#pragma once

#include <vector>
#include <deque>
#include <string>

#ifndef DEBUG
# define DEBUG 0
#endif

class PmergeMe
{
	private:
		std::vector<int> _vec;
		std::deque<int> _deq;

	public:
			PmergeMe();
			PmergeMe(PmergeMe const &right);
			PmergeMe &operator=(PmergeMe const &right);
			~PmergeMe();

			bool parseInput(int ac, char **av);
			void displayBefore() const;
			void displayAfter() const;

			void pairAndSplitVector(std::vector<int> &larger, std::vector<int> &smaller, int &unpaired);
			void pairAndSplitDeque(std::deque<int> &larger, std::deque<int> &smaller, int &unpaired);
			int binarySearchVector(std::vector<int> &arr, int value, int end);
			int binarySearchDeque(std::deque<int> &arr, int value, int end);
			void fordJohnsonSortVector();
			void fordJohnsonSortDeque();

			std::vector<int>& getVector();
			std::deque<int>& getDeque();
};

void mergeSortVector(std::vector<int>& arr, int left, int right);
void mergeVector(std::vector<int>& arr, int left, int mid, int right);		
void mergeSortDeque(std::deque<int>& arr, int left, int right);
void mergeDeque(std::deque<int>& arr, int left, int mid, int right);