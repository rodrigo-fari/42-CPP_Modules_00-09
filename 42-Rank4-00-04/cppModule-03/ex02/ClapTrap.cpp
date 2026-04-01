/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 17:15:47 by rde-fari          #+#    #+#             */
/*   Updated: 2025/11/09 23:47:26 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

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

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap default constructor called." << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ClapTrap::ClapTrap(std::string name)
{
	this->_name = name;
	std::cout << "ClapTrap parameter constructor called." << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << "ClapTrap copy constructor called." << std::endl;
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called." << std::endl;
}

void ClapTrap::setName(std::string name)
{
	this->_name = name;
}

void ClapTrap::setHitPoints(int hitPoints)
{
	this->_hitPoints = hitPoints;
}

void ClapTrap::setEnergyPoints(int energyPoints)
{
	this->_energyPoints = energyPoints;
}

void ClapTrap::setAttackDamage(int attackDamage)
{
	this->_attackDamage = attackDamage;
}

std::string ClapTrap::getName(void)
{
	return (this->_name);
}

int ClapTrap::getHitPoints(void)
{
	return (this->_hitPoints);
}

int ClapTrap::getEnergyPoints(void)
{
	return (this->_energyPoints);
}

int ClapTrap::getAttackDamage(void)
{
	return (this->_attackDamage);
}

void ClapTrap::attack(const std::string &target)
{
	if (this->_energyPoints <= 0)
		std::cout << "ClapTrap " << this->_name
				  << " doesn't have enough E.P. to attack." << std::endl;
	else if (this->_hitPoints <= 0)
		std::cout << "ClapTrap " << this->_name
				  << " doesn't have enough H.P. to attack." << std::endl;
	else
	{
		std::cout << "ClapTrap " << this->_name << " attacks " << target
				  << " causing " << this->_attackDamage << " points of damage!"
				  << std::endl;
		_energyPoints--;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " is already dead!"
				  << std::endl;
	}
	else if ((this->_hitPoints - static_cast<int>(amount)) <= 0)
	{
		this->_hitPoints -= amount;
		std::cout << "ClapTrap " << this->_name << " loses "
				  << amount << " hitpoints." << std::endl;
		std::cout << std::endl;
		std::cout << "ClapTrap " << this->_name << " died." << std::endl;
	}
	else
	{
		this->_hitPoints -= amount;
		std::cout << "ClapTrap " << this->_name << " loses "
				  << amount << " hitpoints." << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name
				  << " doesn't have enough E.P. to be repaired." << std::endl;
	}
	else if (this->_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name
				  << " is already dead, cannot be repaired." << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << this->_name << " is repaired by "
				  << amount << " hit points." << std::endl;
		_energyPoints--;
	}
}
