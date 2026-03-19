/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 12:19:59 by rde-fari          #+#    #+#             */
/*   Updated: 2026/03/19 11:34:13 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <string>
# include <climits>
# include <cstdint>
# include <cstdlib>
# include <cctype>


struct Data
{
	int dataNumber;
	std::string dataString;
};

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer& other);
		Serializer& operator=(const Serializer& other);
		~Serializer();
	public:
		static  uintptr_t serialize(Data* ptr);
		static	Data* deserialize(uintptr_t raw);
};

#endif