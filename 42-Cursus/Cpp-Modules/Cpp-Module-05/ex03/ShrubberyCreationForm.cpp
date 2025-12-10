#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
: AForm("ShrubberyCreationForm", 145, 137)
{
	this->target = "unkown";
	(DEBUG) && std::cout << "ShrubberyCreationForm Constructor Invoked !" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
: AForm("ShrubberyCreationForm", 145, 137)
{
	this->target = target;
	(DEBUG) && std::cout << "Param ShrubberyCreationForm Constructor Invoked !" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm & right)
: AForm(right)
{
	*this = right;
	(DEBUG) && std::cout << "ShrubberyCreationForm Copy Constructor Invoked !" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &right)
{
	(DEBUG) && std::cout << "ShrubberyCreationForm Copy Asseinment Constructor Invoked !" << std::endl;
	if (this != &right)
	{
		this->target = right.target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	(DEBUG) && std::cout << "ShrubberyCreationForm Destructor Invoked !" << std::endl;
}


void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (! (this->get_is_signed() == true) )
		throw (std::runtime_error("Form is not signed ! can't execute !"));
	
	if (executor.getGrade() > this->get_grade_to_execute())
		throw (AForm::GradeTooLowException());
	
	std::ofstream	ofile((target + "_shrubbery").c_str());
	
	if (!ofile.is_open())
        throw std::runtime_error("Failed to create/open file !");
	
	ofile <<
        "       _-_\n"
        "    /~~   ~~\\\n"
        " /~~         ~~\\\n"
        "{               }\n"
        " \\  _-     -_  /\n"
        "   ~  \\\\ //  ~\n"
        "_- -   | | _- _\n"
        "  _ -  | |   -_\n"
        "      // \\\\\n";
        
        ofile.close();
}


void 	ShrubberyCreationForm::beSigned(class Bureaucrat &B)
{
	if (this->get_grade_to_sign() >= B.getGrade())
		this->set_is_signed(true);
	else throw (AForm::GradeTooLowException());
}