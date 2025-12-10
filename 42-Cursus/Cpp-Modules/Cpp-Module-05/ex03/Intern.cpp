#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
	(DEBUG) && std::cout << "Intern Constructor Invoked !" << std::endl;
}

Intern::Intern(const Intern& __attribute__ ((unused)) right)
{
	(DEBUG) && std::cout << "Intern Copy Constructor Invoked !" << std::endl;
	
}

Intern&	Intern::operator=(const Intern __attribute__ ((unused)) &right)
{
	(DEBUG) && std::cout << "Intern Copy Asseinment Invoked !" << std::endl;
	return *this;
}

Intern::~Intern()
{
	(DEBUG) && std::cout << "Intern Destructor Invoked !" << std::endl;
}

AForm*	Intern::makeForm(std::string FormName, std::string target)
{
	std::string forms[3] ={
        "presidential pardon",
        "robotomy request",
		"shrubbery creation"
	};
	
	AForm* (*ptrs[3])(std::string)  = {
		&Intern::ppf,
		&Intern::rrf,
		&Intern::scf
	};
	
	for (int i = 0; i < 3; i++)
	{
		if (FormName == forms[i])
		{
			std::cout << "Intern creates " << FormName << std::endl; 
			return ptrs[i](target);
		}
	}
	
	std::cout <<  "Form name not found !" << std::endl;
	return (NULL);
}

AForm*	Intern::ppf(std::string target)
{
	return new PresidentialPardonForm(target);
}

AForm*	Intern::rrf(std::string target)
{
	return new RobotomyRequestForm(target);
}

AForm*	Intern::scf(std::string target)
{
	return new ShrubberyCreationForm(target);
}