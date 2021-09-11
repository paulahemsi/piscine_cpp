/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 00:37:36 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/09/10 23:57:36 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "includes.hpp"
# include "Contact.hpp"
# include "display.hpp"

# define ADD	"ADD"
# define SEARCH	"SEARCH"
# define EXIT	"EXIT"

class Phonebook {
	private:
		Contact	_contacts[8];
		int		_contact_index;

	public:

		Phonebook(void);
		~Phonebook(void);

		bool add(void);
		bool search(void);
};

#endif
