/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 16:47:13 by rde-fari          #+#    #+#             */
/*   Updated: 2026/04/20 18:33:11 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <string>
# include <sstream>
# include <cstdlib>
# include <iostream>
# include <exception>

class RPN {
	private:
		std::stack<int> _intStack;

		
		public:
		RPN();
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);
		~RPN();
		
		int		calculate(const std::string& expression);
		bool	isMathematicalOperator(const std::string& token);
		void	operationCore(const std::string& mathOperator);

		class InvalidOperationException : public std::exception {
			public:
				const char* what() const throw();
		};
};

#endif