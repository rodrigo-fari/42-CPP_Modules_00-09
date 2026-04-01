/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 20:47:20 by rde-fari          #+#    #+#             */
/*   Updated: 2025/12/21 16:54:29 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <cctype>
# include <iostream>
# include <sstream>

class Animal {
	protected:
		std::string _type;

	public:
		Animal();
		Animal(const Animal &main);
		virtual ~Animal();
		virtual void makeSound() const = 0;
		Animal&	operator=( const Animal& other );

		std::string getType() const;
};

void	msg( std::string msg );

#endif