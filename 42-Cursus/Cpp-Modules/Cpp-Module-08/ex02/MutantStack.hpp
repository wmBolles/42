#pragma once

#ifndef DEBUG
#define DEBUG 0
#endif

#include <stack>
#include <deque>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack();
		MutantStack(const MutantStack & right);
		MutantStack & operator=(const MutantStack & right);
		~MutantStack();
		
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
		
		iterator begin();
		iterator end();
		
		const_iterator begin() const;
		const_iterator end() const;
		
		reverse_iterator rbegin();
		reverse_iterator rend();
		
		const_reverse_iterator rbegin() const;
		const_reverse_iterator rend() const;
};

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>()
{
	(DEBUG) && std::cout << "MutantStack default constructor invoked !" << std::endl;
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T> & right) : std::stack<T>(right)
{
	(DEBUG) && std::cout << "MutantStack copy constructor invoked !" << std::endl;
}

template <typename T>
MutantStack<T> & MutantStack<T>::operator=(const MutantStack<T> & right)
{
	(DEBUG) && std::cout << "MutantStack copy assignment constructor invoked !" << std::endl;
    if (this != &right)
        std::stack<T>::operator=(right);
    return *this;
}

template <typename T>
MutantStack<T>::~MutantStack()
{
	(DEBUG) && std::cout << "MutantStack destructor invoked !" << std::endl;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return this->c.end();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const
{
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const
{
	return this->c.end();
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin()
{
	return this->c.rbegin();
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend()
{
	return this->c.rend();
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rbegin() const
{
	return this->c.rbegin();
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rend() const
{
	return this->c.rend();
}