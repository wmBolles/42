#include "Span.hpp"
#include <stdexcept>

int main()
{
	//subject test
	Span sp = Span(5);
	
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	
	// extra tests
	try
	{
		sp.addNumber(404);
	} catch (std::runtime_error &re) {
		std::cout << re.what() << std::endl;
	}

	std::cout << std::endl;
	
	Span t = Span(1);
	
	t.addNumber(200);
	try{
		try
		{
			t.shortestSpan();
		} catch (std::runtime_error &re) {
			std::cout << re.what() << std::endl;
		}
		t.longestSpan();
	} catch (std::runtime_error &re) {
		std::cout << re.what() << std::endl << std::endl;
	}
	
	// addRange test

	try
	{
		std::vector<int> lmout;
		for (int i = 0; i < 10000; i++)
			lmout.push_back(rand());

		Span sp2(10000);
		sp2.addRange(lmout.begin(), lmout.end());

		std::cout << "Range shortest: " << sp2.shortestSpan() << std::endl;
		std::cout << "Range longest: " << sp2.longestSpan() << std::endl;
	}
	catch (std::runtime_error &re) {
		std::cout << re.what() << std::endl;
	}
	
	try
	{
		std::vector<int> lmout;
		for (int i = 0; i < 10000; i++)
			lmout.push_back(rand());

		Span sp2(100);
		sp2.addRange(lmout.begin(), lmout.end());

		std::cout << "Range shortest: " << sp2.shortestSpan() << std::endl;
		std::cout << "Range longest: " << sp2.longestSpan() << std::endl;
	}
	catch (std::runtime_error &re) {
		std::cout << re.what() << std::endl;
	}
	
	
	std::cout << std::endl;
	return 0;
}