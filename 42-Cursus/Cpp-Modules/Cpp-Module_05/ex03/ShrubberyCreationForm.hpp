#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <string>
#include <fstream>


class ShrubberyCreationForm : public AForm
{
	private :
		std::string		target;
    public :
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm & right);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm &right);
		~ShrubberyCreationForm();
		
		// std::string& get_target();
		void 	beSigned(class Bureaucrat &B);
		void	execute(Bureaucrat const & executor) const;
};