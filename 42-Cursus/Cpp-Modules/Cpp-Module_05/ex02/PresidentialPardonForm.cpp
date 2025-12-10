#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
: AForm("PresidentialPardonForm", 25, 5)
{
	this->target = "unkown";
	(DEBUG) && std::cout << "PresidentialPardonForm Constructor Invoked !" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
: AForm("PresidentialPardonForm", 25, 5)
{
	this->target = target;
	(DEBUG) && std::cout << "Param PresidentialPardonForm Constructor Invoked !" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm & right)
: AForm(right)
{
	*this = right;
	(DEBUG) && std::cout << "PresidentialPardonForm Copy Constructor Invoked !" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &right)
{
	(DEBUG) && std::cout << "PresidentialPardonForm Copy Asseinment Constructor Invoked !" << std::endl;
	if (this != &right)
	{
		this->target = right.target;
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	(DEBUG) && std::cout << "PresidentialPardonForm Destructor Invoked !" << std::endl;
}

void 	PresidentialPardonForm::beSigned(class Bureaucrat &B)
{
	if (this->get_grade_to_sign() >= B.getGrade())
		this->set_is_signed(true);
	else throw (AForm::GradeTooLowException());
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (! (this->get_is_signed() == true) )
		throw (std::runtime_error("Form is not signed ! can't execute !"));
	
	if (executor.getGrade() > this->get_grade_to_execute())
		throw (AForm::GradeTooLowException());
	
	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}