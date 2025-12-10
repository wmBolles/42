#pragma once

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

class Intern
{
	public :
		Intern();
		Intern(const Intern & right);
		Intern& operator=(const Intern &right);
		~Intern();
		AForm*	makeForm(std::string FormName, std::string target);

	private :
		static AForm*	ppf(std::string target);
		static AForm*	rrf(std::string target);
		static AForm*	scf(std::string target);
};