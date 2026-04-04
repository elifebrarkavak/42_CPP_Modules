#include "AForm.hpp"

AForm::AForm() : _name("Default"), _gradeToSign(150), _isSigned(false), _gradeToExecute(150) 
{
	
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) 
	: _name(name), _gradeToSign(gradeToSign), _isSigned(false), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
        throw AForm::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &other) 
	: _name(other._name), _gradeToSign(other._gradeToSign), _isSigned(other._isSigned), 
	  _gradeToExecute(other._gradeToExecute)
{
    
}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
		this->_isSigned = other._isSigned;
	return (*this);
}

AForm::~AForm() 
{

}

std::string AForm::getName() const
{
    return (this->_name);
}

bool AForm::getSigned() const
{
    return (this->_isSigned);
}

int AForm::getGradeToSign() const
{
    return (this->_gradeToSign);
}

int AForm::getGradeToExecute() const
{
    return (this->_gradeToExecute);
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw AForm::GradeTooLowException();
	_isSigned = true;
}
const char *AForm::GradeTooHighException::what() const throw()
{
    return ("Grade is too high!");
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return ("Grade is too low!");
}

const char *AForm::NotSignedException::what() const throw()
{
    return ("Form is not signed!");
}

std::ostream &operator<<(std::ostream &os, const AForm &f)
{
    os << "Form: " << f.getName() << " | Signed: ";
    if (f.getSigned() == true)
    {
        os << "Yes";
    }
    else
    {
        os << "No";
    }
    os << " | Sign Grade: " << f.getGradeToSign();
    os << " | Exec Grade: " << f.getGradeToExecute();

    return (os);
}
