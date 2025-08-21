/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lisux <lisux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 15:52:29 by lguiet            #+#    #+#             */
/*   Updated: 2025/05/22 10:58:14 by lisux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
# define HUMANA_H

#include "Weapon.hpp"

class HumanA{
    private:
        std::string _name;
        Weapon &_weapon;
    public:
        HumanA(const std::string &name, Weapon &weapon);
        ~HumanA();
        void attack()const;
};

#endif