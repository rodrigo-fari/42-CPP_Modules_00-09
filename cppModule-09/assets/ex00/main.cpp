#include "inc/BitcoinExchange.hpp"

#include <iostream>
#include <stdexcept>
#include <string>

static std::string getDatabasePath(const char *programPath) {
    const std::string path(programPath);
    const std::string::size_type slash = path.find_last_of('/');
    const std::string baseDir = (slash == std::string::npos) ? "." : path.substr(0, slash);

    return baseDir + "/../cpp_09/data.csv";
}

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Error: invalid arguments." << std::endl;
        return 1;
    }

    try {
        BitcoinExchange exchange;
        exchange.loadDatabase(getDatabasePath(argv[0]));
        exchange.processInputFile(argv[1]);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
