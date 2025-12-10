#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int         main(void)
{
	Intern	ins;
	AForm	*ret = ins.makeForm("shrubbery creation", "chjra");
	
	if (!ret)
		return (1);
	
	Bureaucrat for_test("test", 1);
	
	try
	{
		ret->beSigned(for_test);
		ret->execute(for_test);
	}
	catch (std::exception &base)
	{
		std::cout << base.what() <<std::endl;
	}
	
	delete ret;
}