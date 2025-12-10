#include "Bureaucrat.hpp"
#include <exception>

Bureaucrat::Bureaucrat(void) : name("unkown")
{
    (DEBUG) && std::cout << "Bureaucrat Constructor Invoked !" << std::endl;
    this->grade = 42;
}

Bureaucrat::Bureaucrat(std::string name, short grade) : name(name)
{
    (DEBUG) && std::cout << "Bureaucrat Param Constructor Invoked !" << std::endl;
    
    if (name.empty())
        throw (std::runtime_error("The Bureaucrat's Name Is Empty !\n"));

    if (grade < 1)
        throw (Bureaucrat::GradeTooHighException());
    else if (grade > 150)
        throw (Bureaucrat::GradeTooLowException());
    else this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &right) : name(right.name)
{
    (DEBUG) && std::cout << "Bureaucrat Copy Constructor Invoked !" << std::endl;
    *this = right;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &right)
{
    (DEBUG) && std::cout << "Bureaucrat Copy Asseinment Invoked !" << std::endl;
    if (this != &right)
        this->grade = right.getGrade();
    return *this;
}

short   Bureaucrat::getGrade() const
{
    return (this->grade);
}

std::string Bureaucrat::getName() const
{
    return (this->name);
}

Bureaucrat::~Bureaucrat()
{
    (DEBUG) && std::cout << "Bureaucrat Destructor Invoked !" << std::endl;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Bureaucrat GradeTooHighException !");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Bureaucrat GradeTooLowException !");
}

void    Bureaucrat::increment()
{
    if (this->grade == 1)
        throw (Bureaucrat::GradeTooHighException());
    else this->grade--;
}

void    Bureaucrat::decrement()
{
    if (this->grade == 150)
        throw (Bureaucrat::GradeTooLowException());
    else this->grade++;
}

// void    Bureaucrat::signForm(Form &form)
// {
//     try
//     {
//         form.beSigned(*this);
//     }
//     catch (std::exception &base)
//     {
//         std::cout << this->getName() << " couldn’t sign " << form.get_Name()
//         << " because ";
//         std::cout << base.what() << std::endl;
//     }
// }

std::ostream& operator<<(std::ostream &obj, const Bureaucrat &right)
{
    obj << right.getName() << ", bureaucrat grade " << right.getGrade() << std::endl;
    return obj;
}

void	Bureaucrat::executeForm(AForm const & form) const
{
	try {
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.get_Name() << std::endl;
	}
	catch (std::exception &base) {
		std::string err = this->getName() + " can not execute " + form.get_Name() + " cuz " + base.what();
		std::cout << err << std::endl; 
	}
}