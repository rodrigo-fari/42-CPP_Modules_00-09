/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 17:15:26 by rde-fari          #+#    #+#             */
/*   Updated: 2026/04/16 17:41:22 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <string>
# include <sstream>
# include <fstream>
# include <iostream>
# include <exception>

class BitcoinExchange {
	private:
		std::map<std::string, double> _dataCsv;

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();

		bool importDatabase(const std::string file);
		
		class InvalidOperationException : public std::exception {
			public:
				virtual const char* what() const throw();	
		};

		class UnableToOpenFileException : public std::exception {
			public:
				virtual const char* what() const throw();	
		};

		class InvalidInputFileException : public std::exception {
			public:
				virtual const char* what() const throw();	
		};
};

std::ostream& operator<<(std::ostream& out, const BitcoinExchange& other);

#endif