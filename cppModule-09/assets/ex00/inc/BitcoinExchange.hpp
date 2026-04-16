#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange {
public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);
    ~BitcoinExchange();

    void loadDatabase(const std::string &csvPath);
    void processInputFile(const std::string &inputPath) const;

private:
    std::map<std::string, double> _rates;

    static std::string trim(const std::string &text);
    static bool isValidDate(const std::string &date);
    static bool parseDouble(const std::string &text, double &value);
    static bool parseValue(const std::string &text, double &value, std::string &errorMessage);

    double findRateForDate(const std::string &date) const;
};

#endif
