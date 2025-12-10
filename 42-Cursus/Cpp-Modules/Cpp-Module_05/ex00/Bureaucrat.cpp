#include "Bureaucrat.hpp"

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
    return ("GradeTooHighException !");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("GradeTooLowException !");
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

std::ostream& operator<<(std::ostream &obj, const Bureaucrat &right)
{
    obj << right.getName() << ", bureaucrat grade " << right.getGrade() << std::endl;
    return obj;
}