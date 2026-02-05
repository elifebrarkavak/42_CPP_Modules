#include "Bureaucrat.hpp"

int main()
{
	std::cout << "--- TEST 1 ---" << std::endl;
	try
	{
		Bureaucrat ebr("Ebrar", 2);
		std::cout << ebr << std::endl;
	
		ebr.incrementGrade(); 
		std::cout << ebr << std::endl;

		ebr.decrementGrade(); 
		std::cout << ebr << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n--- TEST 2 ---" << std::endl;
	try
	{
		Bureaucrat elf("Elif", 0);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return (0);
}