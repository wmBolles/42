#include "Serializer.hpp"

int main() {
    Data d;
    d.val = 42;
    uintptr_t raw = Serializer::serialize(&d);
    Data* ptr = Serializer::deserialize(raw);

    std::cout << "before: " << &d << "\n";
    std::cout << "after: " << ptr << "\n";
    std::cout << "Value: " << ptr->val << "\n";
}