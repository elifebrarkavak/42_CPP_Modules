#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Bureaucrat ebr("Ebrar", 2);
		Bureaucrat elf("Elif", 150);
		
		Form formA("Contract", 5, 20);
		Form formB("Secret Document", 1, 1);

		std::cout << formA << std::endl;
		std::cout << formB << std::endl;

		std::cout << "\n--- Test 1 ---" << std::endl;
		ebr.signForm(formA);
		std::cout << formA << std::endl;

		std::cout << "\n--- Test 2 ---" << std::endl;
		elf.signForm(formA);

		std::cout << "\n--- Test 3 ---" << std::endl;
		ebr.signForm(formB);

	}
	catch (std::exception &e)
	{
		std::cout << "Unexpected exception: " << e.what() << std::endl;
	}

	return (0);
}