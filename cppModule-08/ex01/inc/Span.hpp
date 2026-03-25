/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 21:16:47 by rde-fari          #+#    #+#             */
/*   Updated: 2026/03/25 14:48:03 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <string>
# include <exception>
# include <vector>

class Span {
	private:
		unsigned int _n;
		std::vector<unsigned int> numberVector;

	public:
		Span();
		Span(unsigned int n);
		Span& operator=(const Span& other);
		~Span();

		void addNumber(unsigned int number);
		
		unsigned int shortestSpan();
		unsigned int longestSpan();

		class OutOfBoundesException : public std::exception {
			public:
				const char* what() const throw();	
		};
};

std::ostream& operator<<(std::ostream& out, const Span& rhs);

#endif