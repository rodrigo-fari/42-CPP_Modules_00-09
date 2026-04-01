/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:37:07 by rde-fari          #+#    #+#             */
/*   Updated: 2025/11/10 00:15:07 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

static void sep(const char *title)
{
	std::cout << std::endl
		<< "==================== "
		<< title
		<< " ===================="
		<< std::endl;
}

int main(void)
{
	{
		sep("CLAP TEST");
		ClapTrap trapA;
		ClapTrap trapB("Trap2");
		trapA.setName("Trap1");
		trapA.setAttackDamage(5);
		std::cout << std::endl;
		trapA.attack(trapB.getName());
		trapB.takeDamage(trapA.getAttackDamage());
		std::cout << std::endl;
		trapA.attack(trapB.getName());
		trapB.takeDamage(trapA.getAttackDamage());
		std::cout << std::endl;
		trapA.attack(trapB.getName());
		trapB.takeDamage(trapA.getAttackDamage());
		std::cout << std::endl;
	}
	{
		sep("SCAV TEST");
		ClapTrap clap1;
		ScavTrap scav1("scav1");
		std::cout << std::endl;
		clap1.setName("Clap1");
		clap1.setHitPoints(1);
		scav1.attack(clap1.getName());
		std::cout << std::endl;
		clap1.takeDamage(scav1.getAttackDamage());
		std::cout << std::endl;
		scav1.guardGate();
		std::cout << std::endl;
	}
	{
		sep("FRAG TEST");
		ClapTrap clap1;
		FragTrap frag1("Frag1");
		std::cout << std::endl;
		clap1.setName("Clap1");
		clap1.setHitPoints(1);
		frag1.attack(clap1.getName());
		std::cout << std::endl;
		clap1.takeDamage(frag1.getAttackDamage());
		std::cout << std::endl;
		frag1.highFiveGuys();
		std::cout << std::endl;
		return 0;
	}
}
