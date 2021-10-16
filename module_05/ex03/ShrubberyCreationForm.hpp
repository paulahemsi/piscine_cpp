/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 22:39:08 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/10/15 13:22:54 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		ShrubberyCreationForm(void);
		void	_createFile(void) const;
	public:
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm const& instance);
		~ShrubberyCreationForm(void) {};

		void					execute(Bureaucrat const &executor) const;

		ShrubberyCreationForm	&operator=(ShrubberyCreationForm const &right_hand_side);
};

std::ostream &operator<<(std::ostream &outputFile, ShrubberyCreationForm const &i);

#endif
