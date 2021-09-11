/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 20:03:04 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/09/10 21:28:45 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CONTACT_HPP
# define CONTACT_HPP

# include "includes.hpp"

class Contact {
	public:
		Contact();
		~Contact();

		std::string get_firstName(void) const;
		std::string get_lastName(void) const;
		std::string get_nickName(void) const;
		std::string get_phoneNumber(void) const;
		std::string get_darkestSecret(void) const;

		void set_firstName(std::string buffer);
		void set_lastName(std::string buffer);
		void set_nickName(std::string buffer);
		void set_phoneNumber(std::string buffer);
		void set_darkestSecret(std::string buffer);
		
	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickname;
		std::string	_phoneNumber;
		std::string	_darkestSecret;
};

#endif
