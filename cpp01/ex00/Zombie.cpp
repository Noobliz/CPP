/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiet <lguiet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:43:45 by lguiet            #+#    #+#             */
/*   Updated: 2025/05/21 12:43:46 by lguiet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Zombie.hpp"

Zombie::Zombie(std::string _name){
    name = _name;
}

Zombie::~Zombie()
{
    std::cout<<name
            <<" destroyed"
            <<std::endl;
}

void Zombie::announce(void)const{
    std::cout<<name<<": "
                <<"BraiiiiiiinnnzzzZ..."
                <<std::endl;
}