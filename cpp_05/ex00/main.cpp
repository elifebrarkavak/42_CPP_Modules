#include "Bureaucrat.hpp"

int main()
{
	std::cout << "--- TEST 1 ---" << std::endl;
	try
	{
		Bureaucrat a("Ebrar", 2);
		std::cout << a << std::endl;
	
		a.incrementGrade(); 
		std::cout << a << std::endl;

		a.decrementGrade(); 
		std::cout << a << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n--- TEST 2 ---" << std::endl;
	try
	{
		Bureaucrat b("Elif", 0);

		b.incrementGrade(); 
		std::cout << b << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return (0);
}