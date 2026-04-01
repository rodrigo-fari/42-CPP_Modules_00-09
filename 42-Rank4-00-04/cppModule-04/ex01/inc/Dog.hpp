/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 18:45:42 by rde-fari          #+#    #+#             */
/*   Updated: 2025/12/21 01:54:47 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {
	private:
		Brain* _brain;

	public:
		Dog();
		~Dog();
		Dog(const Dog& main);
		Dog& operator=(const Dog& other);

		void makeSound() const;
		Brain& getBrain() const;
};

# endif