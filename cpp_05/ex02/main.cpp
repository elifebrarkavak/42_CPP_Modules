#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    Bureaucrat ebr("ebr", 1);
    Bureaucrat elf("elf", 50);
    Bureaucrat byz("byz", 138);

    ShrubberyCreationForm shrub("home");
    RobotomyRequestForm robo("Wall-e");
    PresidentialPardonForm pardon("Arthur Dent");

	std::cout << "\n--- Shrubbery ---" << std::endl;
	
	byz.executeForm(shrub);
	byz.signForm(shrub);
	byz.executeForm(shrub);
	elf.executeForm(shrub);

	std::cout << "\n--- Robotomy ---" << std::endl;

	elf.signForm(robo);
	elf.executeForm(robo);
	ebr.executeForm(robo);

	std::cout << "\n--- Presidential Pardon ---" << std::endl;
	
	elf.signForm(pardon);
	ebr.signForm(pardon);
	elf.executeForm(pardon);
	ebr.executeForm(pardon);

    return 0;
}