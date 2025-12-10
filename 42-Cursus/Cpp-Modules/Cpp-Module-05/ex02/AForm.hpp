#pragma once

#include "Bureaucrat.hpp"

enum AForm_STATUS
{
    SIGNED = true,
    NOT_SIGNED = false
};

class Bureaucrat;

class AForm
{
    private:
        const std::string   name;
        bool                is_signed;
        const short         grade_to_sign;
        const short         grade_to_execute;
        
    public:
        AForm();
        AForm(const std::string name, const short grade_to_sign, const short grade_to_execute);
        AForm(const AForm &right);
        AForm& operator=(const AForm &right);
        ~AForm();
        
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
        void			set_is_signed(bool s);
        void            beSigned(Bureaucrat &B);
        
        virtual void	execute(Bureaucrat const & executor) const = 0;
};

std::ostream& operator<<(std::ostream &obj, const AForm &right);