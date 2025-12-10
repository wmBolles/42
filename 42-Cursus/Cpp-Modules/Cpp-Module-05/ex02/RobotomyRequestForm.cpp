#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
// #include <ctime>


RobotomyRequestForm::RobotomyRequestForm()
: AForm("RobotomyRequestForm", 72, 45)
{
	this->target = "unkown";
	(DEBUG) && std::cout << "RobotomyRequestForm Constructor Invoked !" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
: AForm("RobotomyRequestForm", 72, 45)
{
	this->target = target;
	(DEBUG) && std::cout << "Param RobotomyRequestForm Constructor Invoked !" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm & right)
: AForm(right)
{
	*this = right;
	(DEBUG) && std::cout << "RobotomyRequestForm Copy Constructor Invoked !" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &right)
{
	(DEBUG) && std::cout << "RobotomyRequestForm Copy Asseinment Constructor Invoked !" << std::endl;
	if (this != &right)
	{
		this->target = right.target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	(DEBUG) && std::cout << "RobotomyRequestForm Destructor Invoked !" << std::endl;
}

void 	RobotomyRequestForm::beSigned(class Bureaucrat &B)
{
	if (this->get_grade_to_sign() >= B.getGrade())
		this->set_is_signed(true);
	else throw (AForm::GradeTooLowException());
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (! (this->get_is_signed() == true) )
		throw (std::runtime_error("Form is not signed ! can't execute !"));
	
	if (executor.getGrade() > this->get_grade_to_execute())
		throw (AForm::GradeTooLowException());
	
	std::cout << "BOOM! BOOM! VRRRRRRRRR!" << std::endl;
	
	srand(time(NULL));
	if (rand() % 2 == 0)
		std::cout << executor.getName() << " has been robotomized successfully 50% of the time." << std::endl;
	else throw (std::runtime_error("the robotomy failed on " + executor.getName()));	
}