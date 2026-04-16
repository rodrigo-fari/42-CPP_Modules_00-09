#include "../inc/BitcoinExchange.hpp"

#include <cctype>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _rates(other._rates) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
    if (this != &other) {
        _rates = other._rates;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

std::string BitcoinExchange::trim(const std::string &text) {
    std::string::size_type start = 0;
    std::string::size_type end = text.size();

    while (start < end && std::isspace(static_cast<unsigned char>(text[start])) != 0) {
        ++start;
    }
    while (end > start && std::isspace(static_cast<unsigned char>(text[end - 1])) != 0) {
        --end;
    }
    return text.substr(start, end - start);
}

bool BitcoinExchange::isValidDate(const std::string &date) {
    if (date.size() != 10 || date[4] != '-' || date[7] != '-') {
        return false;
    }
    for (std::size_t i = 0; i < date.size(); ++i) {
        if (i == 4 || i == 7) {
            continue;
        }
        if (std::isdigit(static_cast<unsigned char>(date[i])) == 0) {
            return false;
        }
    }

    const int year = std::atoi(date.substr(0, 4).c_str());
    const int month = std::atoi(date.substr(5, 2).c_str());
    const int day = std::atoi(date.substr(8, 2).c_str());

    if (month < 1 || month > 12) {
        return false;
    }

    int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    const bool leapYear = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
    if (leapYear) {
        daysInMonth[1] = 29;
    }

    return day >= 1 && day <= daysInMonth[month - 1];
}

bool BitcoinExchange::parseDouble(const std::string &text, double &value) {
    std::istringstream iss(text);
    char extra = '\0';

    if (!(iss >> value)) {
        return false;
    }
    if (iss >> extra) {
        return false;
    }
    return true;
}

bool BitcoinExchange::parseValue(const std::string &text, double &value, std::string &errorMessage) {
    if (!parseDouble(text, value)) {
        errorMessage = "bad_format";
        return false;
    }
    if (value < 0.0) {
        errorMessage = "Error: not a positive number.";
        return false;
    }
    if (value > 1000.0) {
        errorMessage = "Error: too large a number.";
        return false;
    }
    return true;
}

void BitcoinExchange::loadDatabase(const std::string &csvPath) {
    std::ifstream file(csvPath.c_str());
    if (!file.is_open()) {
        throw std::runtime_error("Error: could not open file.");
    }

    std::string line;
    while (std::getline(file, line)) {
        const std::string trimmedLine = trim(line);
        if (trimmedLine.empty() || trimmedLine == "date,exchange_rate") {
            continue;
        }

        const std::string::size_type comma = trimmedLine.find(',');
        if (comma == std::string::npos) {
            continue;
        }

        const std::string date = trim(trimmedLine.substr(0, comma));
        const std::string rateText = trim(trimmedLine.substr(comma + 1));
        double rate = 0.0;
        if (!isValidDate(date) || !parseDouble(rateText, rate)) {
            continue;
        }
        _rates[date] = rate;
    }

    if (_rates.empty()) {
        throw std::runtime_error("Error: bad database.");
    }
}

double BitcoinExchange::findRateForDate(const std::string &date) const {
    std::map<std::string, double>::const_iterator it = _rates.lower_bound(date);

    if (it != _rates.end() && it->first == date) {
        return it->second;
    }
    if (it == _rates.begin()) {
        throw std::runtime_error("no_lower_date");
    }
    if (it == _rates.end() || it->first > date) {
        --it;
    }
    return it->second;
}

void BitcoinExchange::processInputFile(const std::string &inputPath) const {
    std::ifstream file(inputPath.c_str());
    if (!file.is_open()) {
        throw std::runtime_error("Error: could not open file.");
    }

    std::string line;
    while (std::getline(file, line)) {
        const std::string trimmedLine = trim(line);
        if (trimmedLine.empty()) {
            continue;
        }
        if (trimmedLine == "date | value") {
            continue;
        }

        const std::string::size_type pipe = trimmedLine.find('|');
        if (pipe == std::string::npos) {
            std::cerr << "Error: bad input => " << trimmedLine << std::endl;
            continue;
        }

        const std::string date = trim(trimmedLine.substr(0, pipe));
        const std::string valueText = trim(trimmedLine.substr(pipe + 1));

        if (!isValidDate(date)) {
            std::cerr << "Error: bad input => " << trimmedLine << std::endl;
            continue;
        }

        double value = 0.0;
        std::string errorMessage;
        if (!parseValue(valueText, value, errorMessage)) {
            if (errorMessage == "bad_format") {
                std::cerr << "Error: bad input => " << trimmedLine << std::endl;
            } else {
                std::cerr << errorMessage << std::endl;
            }
            continue;
        }

        try {
            const double rate = findRateForDate(date);
            std::cout << date << " => " << valueText << " = " << (value * rate) << std::endl;
        } catch (const std::exception &) {
            std::cerr << "Error: bad input => " << trimmedLine << std::endl;
        }
    }
}
