/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiet <lguiet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 15:43:44 by lguiet            #+#    #+#             */
/*   Updated: 2025/05/21 16:26:13 by lguiet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string type): _type(type){
    
}

const std::string& Weapon::getType()const
{
    return (_type);
}

void Weapon::setType(const std::string &newType)
{
    _type = newType;
}

// int main ()
// {
//     Weapon weap;

//     weap.setType("gun");
//     std::cout<<weap.getType()<<std::endl;
//     weap.setType("flower");
//     std::cout<<weap.getType()<<std::endl;
// }