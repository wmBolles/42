#pragma once

#include "Weapon.hpp"

class HumanA
{
	private:
		std::string name;
		Weapon& weapon;
	public:
		HumanA(std::string str, Weapon& wapon);
		void attack( void );
};