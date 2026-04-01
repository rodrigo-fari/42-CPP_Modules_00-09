/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 17:15:47 by rde-fari          #+#    #+#             */
/*   Updated: 2025/11/09 23:43:41 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/*
*File organization
===================| OCF |
*Default Constructor
*Parameter Constructor
*Copy Constructor
*Copy assignment constructor (Operator Overload)
*Destructor

===================| Main Methods |
*Take Damage fnct
*Attack fnct
*Be repaired fnct

===================| Getters |
*Get Name fnct
*Get Hit Points fnct
*Get Energy Points fnct
*Get Attack Damage fnct

===================| Setters |
*Set Name fnct
*Set Hit Points fnct
*Set Energy Points fnct
*Set Attack Damage fnct
 */

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap default constructor called." << std::endl;
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap parameter constructor called." << std::endl;
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "ScavTrap copy constructor called." << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
		ClapTrap::operator=(other);
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called." << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->getName()
		<< " is now in Gate keeper mode." << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (this->getEnergyPoints() <= 0)
		std::cout << "ScavTrap " << this->getName()
			<< " doesn't have enough E.P. to attack." << std::endl;
	else if (this->getHitPoints() <= 0)
		std::cout << "ScavTrap " << this->getName()
			<< " doesn't have enough H.P. to attack." << std::endl;
	else
	{
		std::cout << "ScavTrap " << this->getName() << " attacks " << target
			<< " causing " << this->getAttackDamage() << " points of damage!"
			<< std::endl;
		this->setEnergyPoints(this->getEnergyPoints() - 1);
	}
}
