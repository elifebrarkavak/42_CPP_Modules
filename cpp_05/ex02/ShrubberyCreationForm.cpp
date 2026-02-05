#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("Default")
{
	
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), _target(other._target)
{

}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (!this->getSigned())
		throw AForm::NotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();

	std::ofstream file((this->_target + "_shrubbery").c_str());
	if (file.is_open())
	{
		file << "       ccee88oo" << std::endl;
		file << "  C8O8O8Q8PoOb o8oo" << std::endl;
		file << " dOB69QO8PdUOpugoO9bD" << std::endl;
		file << "CgggbU8OU qOp qO8PdUOdcb" << std::endl;
		file << "    6OuU  /p u gcoUodpP" << std::endl;
		file << "      \\\\\\//  /douUP" << std::endl;
		file << "        \\\\\\////" << std::endl;
		file << "         |||/\\" << std::endl;
		file << "         |||\\/" << std::endl;
		file << "         |||||" << std::endl;
		file << "   .....//||||\\...." << std::endl;
		file.close();
	}

}