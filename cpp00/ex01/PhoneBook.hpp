/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lisux <lisux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 14:52:17 by lguiet            #+#    #+#             */
/*   Updated: 2025/05/23 14:20:50 by lisux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"

class PhoneBook
{
private:
	Contact contacts[8];
	int 	nbContacts;
	int 	indexToPlace;

public:
	PhoneBook();

	void 	addContact(const Contact &newContact);
	Contact getContact(const std::string &index) const;
	int 	getNbContacts() const;
	void 	contactList() const;
	~PhoneBook();
};
#endif