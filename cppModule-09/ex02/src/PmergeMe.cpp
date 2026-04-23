/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 18:37:05 by rde-fari          #+#    #+#             */
/*   Updated: 2026/04/23 16:29:44 by rde-fari         ###   ########.fr       */
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

void PmergeMe::setVectorValues(const std::vector<int>& vect) {
	this->_vect = vect;
}

bool PmergeMe::programCore() {
	//TODO: Start na contagem do tempo.
	//TODO: Criacao de pares do vetor. (Sobrante = straggler)
	//TODO: Ordenacao de pares.
	//TODO: Separacao de grupos
	//TODO: 
	//TODO: 
	//TODO: 
	//TODO: 
	return (SUCCESS);
}

std::vector<int>& makePairs(std::vector<int> vect) {
	
}

//*|-------------------------------| AUX FUNCTION DECLARATION |

std::vector<int> stringToIntVector(const std::string &str)
{
	std::vector<int> result;
	std::stringstream ss(str);
	std::string word;
	
	while (ss >> word)
	{
		for (size_t i = 0; i < word.size(); i++)
		{
			if (word[i] == '+' || word[i] == '-')
				throw PmergeMe::SignalsFoundException();
			if (!std::isdigit(word[i]))
				throw PmergeMe::NonNumericExpressionFoundException();
		}
		std::stringstream iss(word);
		long long nbr;
		iss >> nbr;

		if (nbr > INT_MAX || nbr < 0)
			throw PmergeMe::NumberOverBounderiesException();
		
		result.push_back(static_cast<int>(nbr));
	}
	if (!checkDuplicates(result))
		throw PmergeMe::DuplicateNumberFoundException();
	
	return (result);
}

bool checkDuplicates(std::vector<int> vect) {
	
	std::vector<int> vectCopy = vect;
	
	std::sort(vectCopy.begin(), vectCopy.end());
	
	std::vector<int>::iterator verify = std::unique(vectCopy.begin(), vectCopy.end());
	
	if (verify != vectCopy.end())
		return (ERROR);
	return (SUCCESS);
}

//*|-------------------------------| EXCEPTION DECLARATION |

const char* PmergeMe::DuplicateNumberFoundException::what() const throw() {
	return ("Error: No Duplicated number are allowed.");
}

const char* PmergeMe::NonNumericExpressionFoundException::what() const throw() {
	return ("Error: Only numbers are allowed.");
}

const char* PmergeMe::SignalsFoundException::what() const throw() {
	return ("Error: No mathematical symbols are allowed.");
}

const char* PmergeMe::NumberOverBounderiesException::what() const throw() {
	return ("Error: Only INT_LIMIT numbers are allowed.");
}
