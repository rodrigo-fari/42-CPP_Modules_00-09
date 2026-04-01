/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 19:20:02 by rde-fari          #+#    #+#             */
/*   Updated: 2026/03/24 21:06:17 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_H
# define EASYFIND_H

//Libs
# include <iostream>
# include <cstdlib>
# include <iomanip>
# include <limits>
# include <exception>
# include <algorithm>
# include <vector>

//Colors
# define Red "\033[31m"
# define Green "\033[32m"
# define Orange "\033[38;5;208m"
# define Purple "\e[35m"
# define Yellow "\033[33m"
# define Cyan "\033[36m"
# define Reset "\033[0m"

class EmptyContainerException : public std::exception {
	public:
		virtual const char* what() const throw();
};

class NumberDoesNotExistsException : public std::exception {
	public:
		virtual const char* what() const throw();
};

template <typename T> int easyfind(T& container, int n) {
	typename T::iterator it;

	if(container.size() < 1)
		throw EmptyContainerException();
	it = std::find(container.begin(), container.end(), n);
	if (it == container.end())
		throw NumberDoesNotExistsException();
	return (std::distance(container.begin(), it));
}

#endif