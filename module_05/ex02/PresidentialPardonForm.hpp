/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 21:59:07 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/10/16 01:13:44 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:

		PresidentialPardonForm(void);
	public:
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm const& instance);
		~PresidentialPardonForm(void) {};

		bool					execute(Bureaucrat const &executor) const;

		PresidentialPardonForm	&operator=(PresidentialPardonForm const &right_hand_side);
};

std::ostream &operator<<(std::ostream &outputFile, PresidentialPardonForm const &i);


#endif
