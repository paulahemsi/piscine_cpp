
#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

# define V_CYAN			"\e[0;38;5;44m"
# define RESET			"\e[0m"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137)
{
	this->setTarget(target);
	std::cout << *this << std::endl;
	return ;
}

void		ShrubberyCreationForm::_createFile(void)const
{
	std::string line;
	std::string name = this->getTarget() + "_shrubbery";
	std::ofstream outputFile(name.c_str());
	std::ifstream inputFile("trees.txt");

	if(inputFile && outputFile)
	{
		while(getline(inputFile, line))
			outputFile << line << std::endl;
		std::cout << V_CYAN << name << " was sussefuly created and filled with beautifull ASCII trees, go take a look!" << RESET << std::endl;
	}
	else
		std::cout << V_CYAN << "Error creating file" << RESET << std::endl;
	outputFile.close();
	inputFile.close();
}

bool		ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (AForm::execute(executor))
	{
		this->_createFile();
		return (true);
	}
	return (false);
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
