#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <exception>

int         main(void)
{
	try {
		Bureaucrat	wassim("wassim", 1);
		ShrubberyCreationForm sh("chejra");
		
		sh.beSigned(wassim);
		sh.execute(wassim);
		
		
		PresidentialPardonForm pf("pf");
		pf.beSigned(wassim);
		pf.execute(wassim);
		
		
		RobotomyRequestForm	request("req");
		request.beSigned(wassim);
		request.execute(wassim);
		
	} catch (std::exception &base) {
		std::cout << base.what() << std::endl;
	}
	
	
	try {
		Bureaucrat	el_arbi("el_arbi", 1);
		
		ShrubberyCreationForm zitona("zitona");
		PresidentialPardonForm ppf("ppf");
		RobotomyRequestForm	   rrf("rrf");
		
		zitona.beSigned(el_arbi);
		ppf.beSigned(el_arbi);
		rrf.beSigned(el_arbi);
		
		el_arbi.executeForm(zitona);
		el_arbi.executeForm(ppf);
		el_arbi.executeForm(rrf);
		
	} catch (std::exception &base) {
		std::cout << base.what() << std::endl;
	}

}