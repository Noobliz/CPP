/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiet <lguiet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:55:23 by lguiet            #+#    #+#             */
/*   Updated: 2025/05/21 14:37:47 by lguiet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>


class Zombie
{
    private:
        std::string _name;

    public:
        Zombie();
        ~Zombie();
        void setName(const std::string name);
        void announce(void)const;
        
};

Zombie *zombieHorde(int N, std::string name);

# endif