/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 17:47:04 by rde-fari          #+#    #+#             */
/*   Updated: 2025/10/29 15:19:38 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>
# include <cstdlib>

class Zombie {
	private:
		std::string name;

	public:
		Zombie();
		~Zombie();

		void	announce(void);
		void	setName(std::string zName);
};

Zombie*	zombieHorde( int N, std::string name );

#endif