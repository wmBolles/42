#include "Bureaucrat.hpp"

// #pragma clang diagnostic ignored "-Wself-assign-overloaded"

int         main(void)
{
    // Invoking orthodox canonical form funcs //
    // 
    // Bureaucrat bot;
    // bot = bot;
    // Bureaucrat bot2("bot", 1);
    // Bureaucrat test(bot2);
    // Invoking orthodox canonical form funcs //
    
    // try {
    //     Bureaucrat ins;
    //     std::cout << ins.getName() << std::endl;
    //     std::cout << ins.getGrade() << std::endl;
        
    // } catch (std::exception &base) {
    //     std::cout << base.what() << std::endl;
    // }
    
    try
    {
        Bureaucrat wassim("wassim", 1);
        wassim.increment();
    }
    catch (std::exception &base)
    {
        std::cout << base.what() << std::endl;
    }
    
    try
    {
        Bureaucrat wassim("wassim", 150);
        wassim.decrement();
    }
    catch (std::exception &base)
    {
        std::cout << base.what() << std::endl;
    }
    
    try
    {
        Bureaucrat ins("", -1200);
        std::cout << ins;
    }
    catch (std::exception &base) {
        std::cout << base.what();
    }
    
    try
    {
        Bureaucrat ins("mza7a", 1);
        std::cout << ins;
    }
    catch (std::exception &base) {
        std::cout << base.what();
    }
}