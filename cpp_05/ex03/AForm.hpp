#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;

	public:
		AForm();
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		virtual ~AForm();

		AForm(std::string name, int gradeToSign, int gradeToExecute);

		std::string		getName() const;
		bool			getSigned() const;
		int				getGradeToSign() const;
		int				getGradeToExecute() const;

		void			beSigned(const Bureaucrat &bureaucrat);
		

		virtual void	execute(Bureaucrat const & executor) const = 0;

		class GradeTooHighException : public std::exception 
		{
			public: virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public: virtual const char *what() const throw();
		};
		
		class NotSignedException : public std::exception
		{
			public: virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &os, const AForm &f);

#endif