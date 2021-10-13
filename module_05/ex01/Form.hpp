/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 19:44:57 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/10/12 21:06:38 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
	private:
		std::string const	_name;
		bool				_isSigned;
		int const			_gradeToSign;
		int const			_gradeToExecute;
		void				_sign(int grade);

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("\e[0;38;5;9mForm Exception: Grade too high\e[0m");
			}
	};

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("\e[0;38;5;9mForm Exception: Grade too low\e[0m");
			}
	};

	public:
		Form(void);
		Form(std::string name, int gradeToSign, int gradeToexecute);
		Form(Form const& instance);
		~Form(void);

		Form	&operator=(Form const &right_hand_side);

		std::string	getName(void) const;
		int			getGradeToSign(void) const;
		int			getGradeToExecute(void) const;
		bool		getIsSigned(void) const;

		void		beSigned(Bureaucrat const &bureaucrat);
};

std::ostream &operator<<(std::ostream &outputFile, Form const &i);

#endif
