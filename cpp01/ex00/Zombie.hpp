/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiet <lguiet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:43:41 by lguiet            #+#    #+#             */
/*   Updated: 2025/05/21 14:37:40 by lguiet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>

class Zombie
{
    private:
        std::string name;

    public:
        Zombie(std::string _name);
        ~Zombie();
        void announce(void)const;
        
};
    
    Zombie* newZombie(std::string name);
    void randomChump(std::string name);

# endif
