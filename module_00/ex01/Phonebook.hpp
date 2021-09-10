/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 00:37:36 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/09/09 22:22:37 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "includes.hpp"
# include "Contact.hpp"

# define ADD	"ADD"
# define SEARCH	"SEARCH"
# define EXIT	"EXIT"

class Phonebook {
	private:
		Contact contacts[8];
		int		contact_index;

	public:

		Phonebook(void);
		~Phonebook(void);

		bool add(void);
		bool search(void);
};

#endif
