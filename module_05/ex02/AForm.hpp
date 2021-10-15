/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 19:44:57 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/10/14 23:15:02 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		std::string const	_name;
		bool				_isSigned;
		int const			_gradeToSign;
		int const			_gradeToExecute;
		std::string			_target;

		void				_sign(int grade);
		AForm(void);
	protected:

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("\e[0;38;5;9mForm Exception: Grade too high\n\e[0m");
				}
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("\e[0;38;5;9mForm Exception: Grade too low\n\e[0m");
				}
		};

		class NoSignatureException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("\e[0;38;5;9mForm Exception: The form is not signed\n\e[0m");
				}
		};
	public:
		AForm(std::string name, int gradeToSign, int gradeToexecute);
		AForm(AForm const& instance);
		virtual ~AForm(void);

		AForm	&operator=(AForm const &right_hand_side);

		std::string	getName(void) const;
		int			getGradeToSign(void) const;
		int			getGradeToExecute(void) const;
		bool		getIsSigned(void) const;
		std::string	getTarget(void) const;

		void		setTarget(std::string target);

		void		beSigned(Bureaucrat const &bureaucrat);
		void		execute(Bureaucrat const &executor) const;
};

std::ostream &operator<<(std::ostream &outputFile, AForm const &i);

#endif
