/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Student.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:39:29 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/11/02 15:06:57 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <iostream>

class Student
{
	private:
		std::string	_name;
		float		_level;

	public:
		Student(void);
		Student(std::string name, float level);
		Student(Student const &instance);
		~Student(void);

		Student	&operator=(Student const &right_hand_side);

		bool	operator>(Student const &right_hand_side) const;
		bool	operator>=(Student const &right_hand_side) const;
		bool	operator<(Student const &right_hand_side) const;
		bool	operator<=(Student const &right_hand_side) const;
		bool	operator==(Student const &right_hand_side) const;
		bool	operator!=(Student const &right_hand_side) const;

		std::string	getName(void)const;
		float		getLevel(void)const;
};

std::ostream &operator<<(std::ostream &outputFile, Student const &i);

#endif
