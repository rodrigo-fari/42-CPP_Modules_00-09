/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 22:32:34 by rde-fari          #+#    #+#             */
/*   Updated: 2025/12/21 17:15:25 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main(void)
{
	std::cout << std::endl << "=============================================================| SCOPE 1" << std::endl;
	{
		msg("Creation of 'cat' using 'Animal'");
		Animal* cat = new Cat;

		msg("Cat sounds");
		cat->makeSound();

		msg("Cat go to sleep");
		delete cat;

		msg("End of Scope");
	}
	std::cout << std::endl << "=============================================================| SCOPE 2" << std::endl;
	msg("Remove comment on main -> Compilation error, Abstract Classes are nor instaciable!");
	// {
	// 	msg("Creation of 'cat' using 'Animal'");
	// 	Animal cat;

	// 	msg("Cat go to sleep");
	// 	delete cat;

	// 	msg("End of Scope");
	// }
	return (0);
}
