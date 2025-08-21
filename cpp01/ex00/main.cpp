/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiet <lguiet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:42:13 by lguiet            #+#    #+#             */
/*   Updated: 2025/05/21 14:36:45 by lguiet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie *zomb;
    zomb = newZombie("Jack");
    zomb->announce();
    randomChump("Georges");
    Zombie z1("Graouuu");
    {
        Zombie z2("Bonjour");
        z1.announce();
        z2.announce();
    }
    delete zomb;
    return 0;
}