/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiet <lguiet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:58:02 by lguiet            #+#    #+#             */
/*   Updated: 2025/05/21 14:35:42 by lguiet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(){
}

Zombie::~Zombie()
{
    std::cout<<_name
            <<" destroyed"
            <<std::endl;
}

void Zombie::setName(const std::string name)
{
    _name = name;
}
void Zombie::announce(void)const{
    std::cout<<_name<<": "
                <<"BraiiiiiiinnnzzzZ..."
                <<std::endl;
}

