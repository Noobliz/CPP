/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lisux <lisux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 14:52:17 by lguiet            #+#    #+#             */
/*   Updated: 2025/05/13 12:40:30 by lisux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::setInfos(std::string infos[5])
{
	firstName = infos[0];
	lastName = infos[1];
	nickname = infos[2];
	phoneNumber = infos[3];
	darkSecret = infos[4];
}

void Contact::getInfos(std::string contact[5]) const
{
	contact[0] = firstName;
	contact[1] = lastName;
	contact[2] = nickname;
	contact[3] = phoneNumber;
	contact[4] = darkSecret;
}

Contact createContact()
{
	Contact c;

	std::string infos[5];
	std::string input[5] = {"first name ", "last name ",
							"nickname ", "phone number ", "dark secret "};
	for (int i = 0; i < 5; i++)
	{
		std::cout << "enter your " << input[i] << ": ";
		if (!std::getline(std::cin, infos[i]))
		{
			std::cerr << "Error reading stdin." << std::endl;
			return Contact();
		}
		while (infos[i].empty())
		{
			std::cerr << "Error, can't have empty field" << std::endl;
			std::cout << "enter your " << input[i] << ": ";
			if (!std::getline(std::cin, infos[i]))
			{
				std::cerr << "Error reading stdin." << std::endl;
				return Contact();
			}
		}
	}
	c.setInfos(infos);
	return (c);
}
