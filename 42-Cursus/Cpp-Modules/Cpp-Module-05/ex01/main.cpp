#include "Bureaucrat.hpp"
// #include "Form.hpp"
// #include <exception>

// #pragma clang diagnostic ignored "-Wself-assign-overloaded"

int         main(void)
{
    try {
        Form    oracle("orale", 2, 1);
        Bureaucrat chaimaa("chaimaa",2);
        // chaimaa.increment();
        chaimaa.signForm(oracle);
        chaimaa.signForm(oracle);
    } catch (std::exception &base) {
        std::cout << base.what() << std::endl;
    }
    
    try
    {
        Form    leet("1337", 30, 30);
        Bureaucrat wabolles("wabolles", 20);
        
        wabolles.signForm(leet);
        leet.beSigned(wabolles);
    }
    catch(std::exception &base)
    {
        std::cout << base.what() << std::endl;
    }
    try {
        Form    test2("test", 50, 50);
        Bureaucrat b("b", 2);
        test2.beSigned(b);
    } catch (std::exception &base) {
    
    }
}