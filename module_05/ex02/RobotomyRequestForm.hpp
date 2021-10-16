/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 22:35:58 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/10/16 01:14:15 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:

		RobotomyRequestForm(void);
	public:
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm const& instance);
		~RobotomyRequestForm(void) {};

		bool				execute(Bureaucrat const &executor) const;

		RobotomyRequestForm	&operator=(RobotomyRequestForm const &right_hand_side);
};

std::ostream &operator<<(std::ostream &outputFile, RobotomyRequestForm const &i);

#endif
