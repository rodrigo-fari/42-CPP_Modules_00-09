/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 13:40:35 by rde-fari          #+#    #+#             */
/*   Updated: 2026/03/24 13:57:18 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <string>

template<typename T>
void	iter(T* array, const size_t length, void (*func)(T const &)) {
	for(size_t i = 0; i < length; i++) {
		func(array[i]);
	}
}

template<typename T>
void	iter(T* array, const size_t length, void (*func)(T &)) {
	for(size_t i = 0; i < length; i++) {
		func(array[i]);
	}
}

template <typename T>
void	printMsg(T const &output) 
{
	std::cout << output << std::endl;
}

#endif