/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiet <lguiet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 14:34:56 by lguiet            #+#    #+#             */
/*   Updated: 2025/05/21 14:35:08 by lguiet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
    if (N >= 0)
    {
        Zombie *zomb = new Zombie[N];
        for (int i = 0; i < N; i++)
         zomb[i].setName(name);
    
     return (zomb);
    }
    return NULL;
}