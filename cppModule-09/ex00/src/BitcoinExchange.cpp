/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 10:53:30 by rde-fari          #+#    #+#             */
/*   Updated: 2026/04/16 18:02:15 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() { }

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _dataCsv(other._dataCsv) { }

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this != &other) {
		_dataCsv = other._dataCsv;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange() { }

bool BitcoinExchange::importDatabase(const std::string file) {
	std::ifstream openedFile(file.c_str());
	if (!openedFile.is_open())
		throw UnableToOpenFileException();

	std::string splitedLine;
	std::getline(openedFile, splitedLine);
	
	while(std::getline(openedFile,splitedLine))
	{
		size_t commaFind = splitedLine.find(',');
		if (commaFind != std::string::npos)
		{
			std::string date = splitedLine.substr(commaFind + 1).c_str();
			float rate = std::atof(splitedLine.substr(commaFind + 1).c_str());
			_dataCsv[date] = rate;
		}
	}
	openedFile.close();
}

const char* BitcoinExchange::InvalidInputFileException::what() const throw() {
	return ("Error: Input file not valid or missing.");
}

const char* BitcoinExchange::UnableToOpenFileException::what() const throw() {
	return ("Error: Unable to open file.");
}

const char* BitcoinExchange::InvalidOperationException::what() const throw() {
	return ("Error: Invalid operation!");
}

std::ostream& operator<<(std::ostream& out, const BitcoinExchange& other) {
	for (int i = 0; i < )
}