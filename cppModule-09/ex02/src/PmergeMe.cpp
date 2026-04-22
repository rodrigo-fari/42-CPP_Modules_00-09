/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 18:37:05 by rde-fari          #+#    #+#             */
/*   Updated: 2026/04/22 14:40:17 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"



//*|-------------------------------| OCF DECLARATION |

PmergeMe::PmergeMe() { }

PmergeMe::PmergeMe(const PmergeMe& other) : _vect(other._vect), _deck(other._deck) { }

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	if (this != &other) {
		this->_vect = other._vect;
		this->_deck = other._deck;
	}
	return (*this);
}

PmergeMe::~PmergeMe() { }

//*|-------------------------------| MEMBER FUNCTION DECLARATION |


//*|-------------------------------| EXCEPTION DECLARATION |

const char* PmergeMe::DuplicateNumberFoundException::what() const throw() {
	return ("Error: Duplicated number found.");
}

const char* PmergeMe::NonNumericExpressionFoundException::what() const throw() {
	return ("Error: Only integers are allowed on input.");
}

const char* PmergeMe::SignalsFoundException::what() const throw() {
	return ("Error: Invalid mathematical symbol found on input.");
}
