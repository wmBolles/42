#pragma once

#include "Bureaucrat.hpp"
// #include <stdexcept>

enum FORM_STATUS
{
    SIGNED = true,
    NOT_SIGNED = false
};

class Form
{
    private:
        const std::string   name;
        bool                is_signed;
        const short         grade_to_sign;
        const short         grade_to_execute;
        
    public:
        Form();
        Form(const std::string name, const short grade_to_sign, const short grade_to_execute);
        Form(const Form &right);
        Form& operator=(const Form &right);
        ~Form();
        
        class GradeTooHighException : public std::exception
        {
            public:
                const char* what() const throw();
        };
        
        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const throw();
        };
        
        std::string     get_Name() const;
        bool            get_is_signed() const ;
        short           get_grade_to_sign() const ;
        short           get_grade_to_execute() const;
        
        void beSigned(class Bureaucrat &B);
};

std::ostream& operator<<(std::ostream &obj, const Form &right);