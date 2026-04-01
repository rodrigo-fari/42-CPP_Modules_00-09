/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 17:46:59 by rde-fari          #+#    #+#             */
/*   Updated: 2025/06/25 00:06:24 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ) {
	Zombie *zombieHorde;

	zombieHorde = new Zombie[N];
	for(int i = 0; i < N; i++) {
		zombieHorde[i].setName(name);
		std::cout << name << ": has been created." << std::endl;
	}
	return (zombieHorde);
}
