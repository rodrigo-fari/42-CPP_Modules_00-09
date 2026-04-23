/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 18:36:38 by rde-fari          #+#    #+#             */
/*   Updated: 2026/04/23 16:24:55 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <deque>
# include <stack>
# include <string>
# include <vector>
# include <limits>
# include <cstdlib>
# include <sstream>
# include <climits>
# include <iostream>
# include <algorithm>
# include <exception>

# define MICRO_SECONDS " μs."
# define ERROR 0
# define SUCCESS 1
# define MAIN_ERROR 1
# define MAIN_SUCCESS 0

class PmergeMe {
	private:
		std::vector<int> _vect;
		std::deque<int> _deck;

	public:
		//*|-------------------------------| OCF |
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		//*|-------------------------------| MEMBER FUNCTIONS |
		void setVectorValues(const std::vector<int>& vect);
		bool programCore();

		//*|-------------------------------| EXCEPTIONS |
		class DuplicateNumberFoundException : public std::exception {
			public:
				const char* what() const throw();
		};

		class NonNumericExpressionFoundException : public std::exception {
			public:
				const char* what() const throw();
		};

		class SignalsFoundException : public std::exception {
			public:
				const char* what() const throw();
		};

		class NumberOverBounderiesException : public std::exception {
			public:
				const char* what() const throw();
		};
};

//*|-------------------------------| AUX FUNCTIONS |
std::vector<int> stringToIntVector(const std::string &str);
bool checkDuplicates(std::vector<int> vect);


#endif