#include "Base.hpp"
#include <exception>


Base::~Base()
{
	std::cout << "Base Destructor Invoked 1" << std::endl; 
}

A::~A()
{
	std::cout << "A Destructor Invoked 1" << std::endl; 
}
B::~B()
{
	std::cout << "B Destructor Invoked 1" << std::endl; 
}
C::~C()
{
	std::cout << "C Destructor Invoked 1" << std::endl; 
}

// Do not test with following command
// setarch $(uname -m) -R ./Dynamic
// Fixing process stack addresses is undefined behavior
// and using srand()  time(NULL) to depand on the time to set random seeds
// is just cheating from other 42 students ;)

Base	*generate(void)
{
	int		var;
	
	int rand = (uintptr_t) &var;
	int for3 = rand % 3;
	
	if (for3 == 0)
		return new A;
	else if (for3 == 1)
		return (new B);
	else return (new C);
}

void identify(Base* p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "class A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "class B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "Class C" << std::endl;
}

void	identify(Base& p)
{
	try {
		A& __attribute__ ((unused))	a = dynamic_cast<A&>(p); // __attribute__ ((unused)) to avoid unused variable warning instead of casting to void
		std::cout << "Class A" << std::endl;				 // zidk 7ta hadi gift 
		return ;
	}
	catch (std::exception &base) {
		std::cout << base.what() << std::endl;
	}
	
	try
	{
		B&	__attribute__ ((unused)) b = dynamic_cast<B&>(p);
		std::cout << "Class B" << std::endl;
		return ;
	}
	catch (std::exception &base) {
		std::cout << base.what() << std::endl;
	}
	
	try
	{
		C& __attribute__ ((unused))	c = dynamic_cast<C&>(p);
		std::cout << "Class C" << std::endl;
		return ;
	} catch (std::exception &base) {
		std::cout << base.what() << std::endl;
	}
}