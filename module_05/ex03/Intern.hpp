/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 18:39:29 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/10/15 20:58:52 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"

class Intern
{
private:

	AForm	*_createPresidentialForm(std::string target);
	AForm	*_createRobotomyForm(std::string target);
	AForm	*_createShrubberyForm(std::string target);

public:
	Intern(void);
	~Intern(void);
	Intern(Intern const& instance);

	Intern	&operator=(Intern const &right_hand_side);

	AForm	*makeForm(std::string name, std::string target);
};

#endif
