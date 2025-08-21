/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiet <lguiet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:41:44 by lguiet            #+#    #+#             */
/*   Updated: 2025/05/21 12:42:54 by lguiet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Zombie.hpp"


Zombie* newZombie(std::string name){
    Zombie *zomb;
    zomb = new Zombie(name);

    return (zomb);
}
