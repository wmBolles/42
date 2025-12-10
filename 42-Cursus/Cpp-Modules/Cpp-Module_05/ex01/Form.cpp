#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("empty"), grade_to_sign(42), grade_to_execute(42)
{
    (DEBUG) && std::cout << "Form Constructor Invoked !" << std::endl;
    this->is_signed = NOT_SIGNED;
}

Form::Form(const std::string name, const short grade_to_sign, const short grade_to_execute)
    :name(name),
    is_signed(NOT_SIGNED),
    grade_to_sign(grade_to_sign),
    grade_to_execute(grade_to_execute)
{
    (DEBUG) && std::cout << "Form Param Constructor Invoked !" << std::endl;
    bool GTL = (this->grade_to_execute > 150 || this->grade_to_sign > 150);
    if (GTL)
        throw (Form::GradeTooLowException());
    
    bool GTH =  (this->grade_to_execute < 1 || this->grade_to_sign < 1);
    if (GTH)
        throw (Form::GradeTooHighException());
}

Form::Form(const Form &right)
    :name(right.name),
    grade_to_sign(right.grade_to_sign),
    grade_to_execute(right.grade_to_execute)
{
    (DEBUG) && std::cout << "Form Copy Constructor Invoked !" << std::endl;
    *this = right;
}

Form& Form::operator=(const Form &right)
{
    (DEBUG) && std::cout << "Form Copy Asseinment Invoked !" << std::endl;
    if (this != &right)
        this->is_signed = right.is_signed;
    return (*this);
}

Form::~Form()
{
    (DEBUG) && std::cout << "Form Destructor Invoked !" << std::endl;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return ("Form GradeTooHighException !");
}

const char* Form::GradeTooLowException::what() const throw()
{
    return ("Form GradeTooLowException !");
}


// getters
std::string     Form::get_Name() const
{
    return (this->name);
}
bool            Form::get_is_signed() const
{
    return (this->is_signed);
}
short           Form::get_grade_to_sign() const
{
    return (this->grade_to_sign);
}
short           Form::get_grade_to_execute() const
{
    return (this->grade_to_execute);
}

void            Form::beSigned(Bureaucrat &B)
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
        throw (Form::GradeTooLowException());
} // hadi khasha chi garo hhhhh

std::ostream& operator<<(std::ostream &form,const Form &right)
{
    form << "NAME: " << right.get_Name() << std::endl
    << "Is Signed: " << right.get_is_signed() << std::endl
    << "Grade To Sign: " << right.get_grade_to_sign() << std::endl
    << "Grade To Exeute: " << right.get_grade_to_execute() << std::endl;
    return form;
}