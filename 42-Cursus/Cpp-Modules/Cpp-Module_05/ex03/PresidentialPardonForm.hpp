#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private :
		std::string		target;
    public :
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm & right);
		PresidentialPardonForm& operator=(const PresidentialPardonForm &right);
		~PresidentialPardonForm();
		
		// std::string& get_target();
		void 	beSigned(class Bureaucrat &B);
		void	execute(Bureaucrat const & executor) const;
};