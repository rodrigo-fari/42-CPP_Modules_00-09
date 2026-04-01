/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 15:11:37 by rde-fari          #+#    #+#             */
/*   Updated: 2025/06/25 18:00:51 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanB.hpp"

HumanB::HumanB(std::string name) {
	this->name = name;
	this->weapon = NULL;
}

void	HumanB::setWeapon(Weapon& newWeapon) {
	weapon = &newWeapon;
}

void	HumanB::attack() const {
	if (weapon == NULL)
		std::cout << name << " tryed to attack with empty hands. lol, crazy guy xd " << std::endl;
	else
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}
