/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 17:46:57 by rde-fari          #+#    #+#             */
/*   Updated: 2025/10/29 14:39:35 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void) {
	Zombie *z1 = newZombie("Foo");
	z1->announce();
	std::cout << std::endl;
	
	Zombie *z2 = newZombie("z2");
	z2->announce();
	std::cout << std::endl;
	
	randomChump("z3");
	std::cout << std::endl;
	
	delete(z1);
	delete(z2);
	return (0);
}
