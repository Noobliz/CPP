/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lisux <lisux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 14:52:07 by lguiet            #+#    #+#             */
/*   Updated: 2025/05/13 12:46:04 by lisux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <sstream>

bool isnum(char c)
{
	if (c < '0' || c > '9')
		return false;
	return true;
}
PhoneBook::PhoneBook() : nbContacts(0), indexToPlace(0)
{
	std::cout << "Welcome to your phonebook" << std::endl;
}

void PhoneBook::addContact(const Contact &newContact)
{
	contacts[indexToPlace] = newContact;
	if (indexToPlace < 7)
		indexToPlace++;
	else
		indexToPlace = 0;
	if (nbContacts < 8)
		nbContacts++;
}
Contact PhoneBook::getContact(const std::string &sindex) const
{
	int index = sindex[0] - '0';
	if (index < 0 || index > nbContacts)
	{
		std::cerr << "index should between 0 and "<<nbContacts << std::endl;
		return Contact();
	}
	return contacts[index];
}

int PhoneBook::getNbContacts() const
{
	return nbContacts;
}

PhoneBook::~PhoneBook()
{
	std::cout << "it's been an honor to serve, bye !" << std::endl;
}
std::string	fFormat(const std::string str)
{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	std::stringstream ss;
	ss << std::setw(10) << str;
	return ss.str();
}
void PhoneBook::contactList() const
{
	std::cout << "|-------------------------------------------|" << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	for (int i = 0; i < nbContacts; i++)
	{
		std::string contact[5];
		contacts[i].getInfos(contact);
		std::cout <<"|" << std::setw(10) << i << "|"
		          << fFormat(contact[0]) << "|"
		          << fFormat(contact[1]) << "|"
		          << fFormat(contact[2]) << "|" << std::endl;
	}
	std::cout << "|-------------------------------------------|" << std::endl;
}

int main()
{
	PhoneBook book;
	std::string cmd;
	while (cmd != "EXIT")
	{
		std::cout	<< "enter ADD, SEARCH or EXIT" << std::endl
					<< ">> ";
		if (!std::getline(std::cin, cmd))
		{
			std::cerr << "Error reading stdin." << std::endl;
			return 1;
		}
		if (cmd == "ADD")
		{
			Contact newContact;
			newContact = createContact();
			book.addContact(newContact);
		}
		if (cmd == "SEARCH")
		{
			if (book.getNbContacts() == 0)
			{
				std::cout<<"Please, Add a contact first"<<std::endl;
				continue;
			}
			book.contactList();
			std::string sIndex;
			while (true)
			{
				std::cout << "Enter your contact index (0 to " << book.getNbContacts() - 1 << "): ";
				if (!std::getline(std::cin, sIndex))
				{
					std::cout << std::endl;
					std::cerr << "Error reading stdin." << std::endl;
					return 1;
				}
				if (sIndex.length() != 1 || !isnum(sIndex[0]) || (sIndex[0] - '0' > book.getNbContacts() - 1))
				{
					std::cerr << "Invalid input. Try again." << std::endl;
					continue;
				}
				break;
			}
			Contact contactN;
			contactN = book.getContact(sIndex);
			std::string contactDisplay[5];
			contactN.getInfos(contactDisplay);
			for (int i = 0; i < 5; i++)
			{
				std::cout << contactDisplay[i] << std::endl;
			}
		}
	}
}