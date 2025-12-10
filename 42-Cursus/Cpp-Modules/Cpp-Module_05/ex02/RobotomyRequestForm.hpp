#pragma once

#include "AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm : public AForm
{
	private :
		std::string		target;
    public :
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm & right);
		RobotomyRequestForm& operator=(const RobotomyRequestForm &right);
		~RobotomyRequestForm();
		
		// std::string& get_target();
		void 	beSigned(class Bureaucrat &B);
		void	execute(Bureaucrat const & executor) const;
};