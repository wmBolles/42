#pragma once

#include <iostream>
#include <vector>
#include <algorithm>


template <typename T>
int easyfind(T & v, int value)
{
	typename T::iterator it = std::find(v.begin(), v.end(), value);
	if (it == v.end())
		throw std::out_of_range("value not found !");
	return *it;
}