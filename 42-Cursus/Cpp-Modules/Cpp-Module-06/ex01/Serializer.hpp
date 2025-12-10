#pragma once

#include <iostream>
// #include <cstdint>
#include <stdint.h>


struct Data
{
	int	val;	
};

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer& right);
		Serializer& operator=(const Serializer& right);
		~Serializer();
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};