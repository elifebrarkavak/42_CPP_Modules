#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Bureaucrat a("Ebrar", 2);
		Bureaucrat b("Elif", 150);
		
		Form formA("Contract", 5, 20);
		Form formB("Secret Document", 1, 1);

		std::cout << formA << std::endl;
		std::cout << formB << std::endl;

		std::cout << "\n--- Test 1 ---" << std::endl;
		a.signForm(formA);
		std::cout << formA << std::endl;

		std::cout << "\n--- Test 2 ---" << std::endl;
		b.signForm(formA);

		std::cout << "\n--- Test 3 ---" << std::endl;
		a.signForm(formB);

	}
	catch (std::exception &e)
	{
		std::cout << "Unexpected exception: " << e.what() << std::endl;
	}

	return (0);
}