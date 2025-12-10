#pragma once

#include <exception>
#include <cstddef>
#include <iostream>

#ifndef DEBUG
# define DEBUG 0
#endif

template <typename T>
class Array
{
	private:
		T*		_array;
		size_t	_size;
	
	public:
		Array();
		Array(unsigned int n);
		Array(Array const & src);
		Array & operator=(Array const & rhs);
		~Array();

		T & operator[](size_t index);
		T const & operator[](size_t index) const;
		size_t size() const;

		class OutOfBoundsException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "Array index out of bounds";
				}
		};
};


template <typename T>
Array<T>::Array()
{
	(DEBUG) && (std::cout << "default constructor invoked!" << std::endl);
	_array = NULL;
	_size	= 0;
}

template <typename T>
Array<T>::Array(unsigned int n) : _array(NULL), _size(n)
{
	(DEBUG) && (std::cout << "param constructor invoked!" << std::endl);
	
	if (n > 0)
		_array = new T[n]();
}

template <typename T>
Array<T>::Array(Array const & right)
{
	(DEBUG) && (std::cout << "copy constructor invoked!" << std::endl);
	
	_array = NULL;
	_size = right._size;
	if (_size > 0)
	{
		_array = new T[_size];
		for (size_t i = 0; i < _size; i++)
			_array[i] = right._array[i];
	}
}

template <typename T>
Array<T> & Array<T>::operator=(Array const & right)
{
	if (this != &right)
	{
		if (_array != NULL)
			delete[] _array;

		_size = right._size;
		_array = NULL;
		
		if (_size > 0)
		{
			_array = new T[_size];
			for (size_t i = 0; i < _size; i++)
				_array[i] = right._array[i];
		}
	}
	return *this;
}

template <typename T>
Array<T>::~Array()
{
	if (_array != NULL)
		delete[] _array;
}

template <typename T>
T & Array<T>::operator[](size_t index)
{
	if (index >= _size)
		throw OutOfBoundsException();
	return _array[index];
}

template <typename T>
T const & Array<T>::operator[](size_t index) const
{
	if (index >= _size)
		throw OutOfBoundsException();
	return _array[index];
}

template <typename T>
size_t Array<T>::size() const
{
	return _size;
}