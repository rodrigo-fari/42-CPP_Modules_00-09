/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 18:36:38 by rde-fari          #+#    #+#             */
/*   Updated: 2026/04/22 14:29:35 by rde-fari         ###   ########.fr       */
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
# include <exception>

# define MICRO_SECONDS " μs."

class PmergeMe {
	private:
		std::vector<int> _vect;
		std::deque<int> _deck;

	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		

		
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
};

#endif