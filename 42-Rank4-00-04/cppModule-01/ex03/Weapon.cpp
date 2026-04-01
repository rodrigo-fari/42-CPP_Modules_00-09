/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 14:47:20 by rde-fari          #+#    #+#             */
/*   Updated: 2025/06/25 17:32:44 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string initialType) : type(initialType) {}

const	std::string& Weapon::getType() const {
	return (type);
}

void	Weapon::setType(const std::string& newType) {
	type = newType;
}
