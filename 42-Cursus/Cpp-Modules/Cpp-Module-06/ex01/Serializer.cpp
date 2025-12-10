#include "Serializer.hpp"
// #include <cstdint>

Serializer::Serializer() {}
Serializer::~Serializer() {}
Serializer::Serializer(const Serializer& right) { *this = right; }
Serializer& Serializer::operator=(const Serializer& __attribute__ ((unused)) right)
{
	return *this;
}

uintptr_t Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}