#include "iter.hpp"

static void increment(int & n)
{
	n++;
}

int main(void)
{
    int *ptr = NULL;
    iter(ptr, -66, print<int>);

	int intArray[] = {1, 2, 3, 4, 5};
	iter(intArray, 5, print<int>);
	std::cout << std::endl;

	std::cout << "Before: ";
	iter(intArray, 5, print<int>);
	std::cout << std::endl;
	
	iter(intArray, 5, increment);
	
	std::cout << "After:  ";
	iter(intArray, 5, print<int>);
	std::cout << std::endl;

	return 0;
}