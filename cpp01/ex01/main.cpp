/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiet <lguiet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 14:33:49 by lguiet            #+#    #+#             */
/*   Updated: 2025/05/21 14:34:05 by lguiet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(){

    int N = 5;
    Zombie *zomb = zombieHorde(N, "bob");
    
    for (int i = 0; i < N; i++)
    {
        std::cout<<"zombi["<<i<<"] ";
        zomb[i].announce();
    }
    delete []zomb;
        
}