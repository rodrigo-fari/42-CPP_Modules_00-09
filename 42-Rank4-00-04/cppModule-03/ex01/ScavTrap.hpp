/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 17:07:41 by rde-fari          #+#    #+#             */
/*   Updated: 2025/11/09 23:42:15 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <string>
#include <cctype>
#include <iostream>
#include <sstream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
	// Orthodox Canonical Form
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &other);
	ScavTrap &operator=(const ScavTrap &other);
	~ScavTrap();

	// Special behaviour
	void guardGate();
	// Override attack to identify ScavTrap
	void attack(const std::string &target);
};

#endif