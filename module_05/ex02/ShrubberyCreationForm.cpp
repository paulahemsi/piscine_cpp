
#include "ShrubberyCreationForm.hpp"
#include <iostream>

# define V_CYAN			"\e[0;38;5;44m"
# define RESET			"\e[0m"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137)
{
	this->setTarget(target);
	std::cout << *this << std::endl;
	return ;
}

void		ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	try
	{
		AForm::execute(executor);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return ;
	}
	std::cout << V_CYAN << this->getTarget() << " TODO CREATE FILE ON TARGET DIRECTORY" << RESET << std::endl;
}

std::ostream &operator<<(std::ostream &outputFile, ShrubberyCreationForm const &i)
{
	outputFile	<< V_CYAN
				<< i.getName()
				<< std::endl
				<< "Grade to sign: "
				<< i.getGradeToSign()
				<< std::endl
				<< "Grade to execute: "
				<< i.getGradeToExecute()
				<< std::endl
				<< "Target: "
				<< i.getTarget()
				<< std::endl
				<< "Is signed: ";
	if (i.getIsSigned())
		outputFile << "Yes." << RESET << std::endl;
	else
		outputFile << "No." << RESET << std::endl;
	return (outputFile);
}
