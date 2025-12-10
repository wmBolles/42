#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("empty"), grade_to_sign(42), grade_to_execute(42)
{
    (DEBUG) && std::cout << "AForm Constructor Invoked !" << std::endl;
    this->is_signed = NOT_SIGNED;
}

AForm::AForm(const std::string name, const short grade_to_sign, const short grade_to_execute)
    :name(name),
    is_signed(NOT_SIGNED),
    grade_to_sign(grade_to_sign),
    grade_to_execute(grade_to_execute)
{
    (DEBUG) && std::cout << "AForm Param Constructor Invoked !" << std::endl;
    bool GTL = (this->grade_to_execute > 150 || this->grade_to_sign > 150);
    if (GTL)
        throw (AForm::GradeTooLowException());
    
    bool GTH =  (this->grade_to_execute < 1 || this->grade_to_sign < 1);
    if (GTH)
        throw (AForm::GradeTooHighException());
}

AForm::AForm(const AForm &right)
    :name(right.name),
    grade_to_sign(right.grade_to_sign),
    grade_to_execute(right.grade_to_execute)
{
    (DEBUG) && std::cout << "AForm Copy Constructor Invoked !" << std::endl;
    *this = right;
}

AForm& AForm::operator=(const AForm &right)
{
    (DEBUG) && std::cout << "AForm Copy Asseinment Invoked !" << std::endl;
    if (this != &right)
        this->is_signed = right.is_signed;
    return (*this);
}

AForm::~AForm()
{
    (DEBUG) && std::cout << "AForm Destructor Invoked !" << std::endl;
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return ("GradeTooHighException !");
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return ("GradeTooLowException !");
}


// getters
std::string     AForm::get_Name() const
{
    return (this->name);
}
bool            AForm::get_is_signed() const
{
    return (this->is_signed);
}
short           AForm::get_grade_to_sign() const
{
    return (this->grade_to_sign);
}
short           AForm::get_grade_to_execute() const
{
    return (this->grade_to_execute);
}

void            AForm::beSigned(Bureaucrat &B)
{
    if (this->is_signed)
    {
        throw (std::runtime_error("Already Signed !"));
    }
    if (B.getGrade() <= this->grade_to_sign)
    {
        this->is_signed = SIGNED;
        std::cout << B.getName() << " signed " << this->get_Name() << std::endl;
    }   
    else
        throw (AForm::GradeTooLowException());
}

void			AForm::set_is_signed(bool s)
{
	this->is_signed = s;
}

void	AForm::execute(Bureaucrat __attribute__ ((unused)) const & executor) const
{
	return ; // nothing to do 7itach it's a base class u can call this func directly
}


// error due to aform is an ab class
// std::ostream& operator<<(std::ostream &AForm, const AForm &right)
// {
//     AForm << "NAME: " << right.get_Name() << std::endl
//     << "Is Signed: " << right.get_is_signed() << std::endl
//     << "Grade To Sign: " << right.get_grade_to_sign() << std::endl
//     << "Grade To Exeute: " << right.get_grade_to_execute() << std::endl;
//     return AForm;
// }
