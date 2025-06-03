#pragma once

#include <iostream>

class Brain
{
    private:
        std::string ideas[100];    
    public:
        Brain();
        Brain(const Brain& rhs);
        Brain& operator=(const Brain & rhs);
        ~Brain();
};