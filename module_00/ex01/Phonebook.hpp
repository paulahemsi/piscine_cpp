/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 00:37:36 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/09/11 20:54:32 by phemsi-a         ###   ########.fr       */
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

class Phonebook
{
	private:
		Contact		_contacts[8];
		int			_lastIndex;
		int			_defineLastIndex(void);
		int			_getIndex(void);
		void		_displayContact(int i);
		void		_displayTable(void);
		void		_displayContact(void);
		void		_displayLine(int id);
		bool		_contact(Contact contact);
		std::string	_truncate(std::string value, size_t limit);

	public:
		Phonebook(void);
		~Phonebook(void);

		bool	add(void);
		bool	search(void);
};

#endif
