/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 17:46:57 by rde-fari          #+#    #+#             */
/*   Updated: 2025/10/29 15:23:42 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main( void ) {
	int n = 100;
	Zombie* horde = zombieHorde(n, "zombie");
	for(int i = 0; i < n; i++) {
		std::cout << "[ " << (i + 1) << " ] ";
		horde[i].announce();
	}
	delete[] horde;
}

//* How many have been created: ./zombie | grep "created" | wc -l 
//! How many have been destroyed: ./zombie | grep "destroyed" | wc -l 