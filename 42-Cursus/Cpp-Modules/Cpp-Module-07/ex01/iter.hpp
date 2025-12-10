#pragma once

#include <cstddef>
#include <iostream>

template <typename T, typename F>
void iter(T* array, size_t length, F func)
{
	if (array == NULL)
		return;
	for (size_t i = 0; i < length; i++)
		func(array[i]);
}

template <typename T>
void print(T & x)
{
	std::cout << x << " ";
}
