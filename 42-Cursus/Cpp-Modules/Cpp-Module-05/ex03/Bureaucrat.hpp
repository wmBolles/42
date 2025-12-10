#pragma once

#include <iostream>
#include <exception>
#include <ostream>

#ifndef DEBUG
# define DEBUG 0
#endif

#include "AForm.hpp"

class AForm;

class Bureaucrat
{
    private:
        const std::string     name;
        short                grade;

    public:
        Bureaucrat();
        Bureaucrat(std::string name, short grade);
        Bureaucrat(const Bureaucrat &right);
        Bureaucrat& operator=(const Bureaucrat &right);
        ~Bureaucrat();

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
        
        short   getGrade() const; 
        std::string getName() const;
        void    increment();
        void    decrement();
        
        // void    signForm(class Form &form);
        void executeForm(AForm const & form) const;
};

std::ostream& operator<<(std::ostream &obj, const Bureaucrat &right);