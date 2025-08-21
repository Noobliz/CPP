/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lisux <lisux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 16:00:59 by lguiet            #+#    #+#             */
/*   Updated: 2025/05/22 11:04:10 by lisux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(const std::string &name, Weapon &weapon): _name(name), _weapon(weapon){   
}

HumanA::~HumanA(){
    
}

void HumanA::attack()const{
    
    std::cout<<_name
             <<" attacks with their "<<_weapon.getType()
             <<std::endl;
}
