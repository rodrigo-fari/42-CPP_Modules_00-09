/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 17:07:41 by rde-fari          #+#    #+#             */
/*   Updated: 2025/11/10 00:08:56 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <string>
#include <cctype>
#include <iostream>
#include <sstream>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
	// Orthodox Canonical Form
	FragTrap();
	FragTrap(std::string name);
	FragTrap(const FragTrap &other);
	FragTrap &operator=(const FragTrap &other);
	~FragTrap();

	// Special behaviour
	void highFiveGuys( void );
	// Override attack to identify ScavTrap
	void attack(const std::string &target);
};

#endif