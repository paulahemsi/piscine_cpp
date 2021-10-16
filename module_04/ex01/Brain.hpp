/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 21:11:56 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/10/16 18:35:34 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
	private:
		static std::string _rawIdeas[100];
	protected:
	public:
		std::string ideas[100];
		Brain(void);
		Brain(Brain const& instance);
		~Brain(void);
		void operator=(Brain const &right_hand_side);
};

#endif
