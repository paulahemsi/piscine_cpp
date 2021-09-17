/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 20:41:53 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/09/16 21:52:13 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef KAREN_HPP
# define KAREN_HPP

# include <iostream>
# include "colors.hpp"

# define K_DEBUG	GREEN \
					"I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!" \
					RESET
# define K_INFO		YELLOW \
					"I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!" \
					RESET
# define K_WARNING	ORANGE \
					"I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month." \
					RESET
# define K_ERROR	RED \
					"This is unacceptable, I want to speak to the manager now." \
					RESET

class Karen
{
	private:
		void debug (void);
		void info (void);
		void warning (void);
		void error (void);

	public:
		Karen(void);
		~Karen(void);
		void complain(std::string level);
};

# endif
