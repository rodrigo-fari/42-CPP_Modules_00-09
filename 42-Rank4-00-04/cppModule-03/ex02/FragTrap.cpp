/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 17:15:47 by rde-fari          #+#    #+#             */
/*   Updated: 2025/11/10 00:10:36 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

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

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap default constructor called." << std::endl;
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap parameter constructor called." << std::endl;
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "FragTrap copy constructor called." << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	std::cout << "FragTrap copy assignment operator called." << std::endl;
	if (this != &other)
		ClapTrap::operator=(other);
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called." << std::endl;
}

void FragTrap::highFiveGuys( void )
{
	std::cout << "FragTrap " << this->getName()
		<< " is about to make a positive high-five request..." << std::endl;
}

void FragTrap::attack(const std::string &target)
{
	if (this->getEnergyPoints() <= 0)
		std::cout << "FragTrap " << this->getName()
			<< " doesn't have enough E.P. to attack." << std::endl;
	else if (this->getHitPoints() <= 0)
		std::cout << "FragTrap " << this->getName()
			<< " doesn't have enough H.P. to attack." << std::endl;
	else
	{
		std::cout << "FragTrap " << this->getName() << " attacks " << target
			<< " causing " << this->getAttackDamage() << " points of damage!"
			<< std::endl;
		this->setEnergyPoints(this->getEnergyPoints() - 1);
	}
}
