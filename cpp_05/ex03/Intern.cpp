#include "Intern.hpp"

Intern::Intern()
{

}

Intern::Intern(const Intern &other)
{
	(void)other; 
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return (*this);
}

Intern::~Intern()
{

}

AForm *Intern::makeForm(std::string form, std::string target)
{
    std::string forms[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    int index = -1;

    for (int i = 0; i < 3; i++)
	{
        if (form == forms[i])
		{
            index = i;
            break;
        }
    }

    switch (index)
	{
        case 0:
            std::cout << "Intern creates " << form << std::endl;
            return new ShrubberyCreationForm(target);
        case 1:
            std::cout << "Intern creates " << form << std::endl;
            return new RobotomyRequestForm(target);
        case 2:
            std::cout << "Intern creates " << form << std::endl;
            return new PresidentialPardonForm(target);
        default:
            std::cout << "Error! Form '" << form << "' doesn't exist!" << std::endl;
            return NULL;
    }
}
