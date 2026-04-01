/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:37:07 by rde-fari          #+#    #+#             */
/*   Updated: 2025/11/06 17:53:05 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main ( void ) {
	{
		std::cout << "========== MAIN 1 ==========" << std::endl;

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
	// {
	// 	std::cout << "========== MAIN 2 ==========" << std::endl;
	// 	std::cout << std::endl;
	// 	ClapTrap trapA("Trap1");
	// 	ClapTrap trapB("Trap2");

	// 	trapA.setAttackDamage(1);
	// 	std::cout << std::endl;
	// 	std::cout << std::endl;
	// 	for(int i = 1; i <= 11; i++) {
	// 		trapA.attack(trapB.getName());
	// 		std::cout << std::endl;
	// 		trapB.takeDamage(trapA.getAttackDamage());
	// 		std::cout << std::endl;
	// 	}
	// }
}
