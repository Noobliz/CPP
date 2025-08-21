/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiet <lguiet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 15:32:59 by lguiet            #+#    #+#             */
/*   Updated: 2025/05/21 16:24:29 by lguiet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H

# include <iostream>

class Weapon{
    private:
        std::string _type;
    public:
        Weapon(const std::string type);
        const std::string& getType()const;
        void setType(const std::string &newType);
};

#endif
