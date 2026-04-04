#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    Bureaucrat a("Ebrar", 1);
    Bureaucrat b("Elif", 50);
    Bureaucrat c("Beyza", 138);

    ShrubberyCreationForm shrub("backyard");
    RobotomyRequestForm robo("Marvin");
    PresidentialPardonForm pardon("Criminal_X");

	std::cout << "\n--- Shrubbery Test---" << std::endl;
	
	c.executeForm(shrub);
	c.signForm(shrub);
	c.executeForm(shrub);
	b.executeForm(shrub);

	std::cout << "\n--- Robotomy Test---" << std::endl;

	b.signForm(robo);
	b.executeForm(robo);
	a.executeForm(robo);

	std::cout << "\n--- Presidential Pardon Test---" << std::endl;
	
	b.signForm(pardon);
	a.signForm(pardon);
	b.executeForm(pardon);
	a.executeForm(pardon);

    return 0;
}