#include "inc/RPN.hpp"

#include <iostream>
#include <stdexcept>

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    try {
        RPN calculator;
        std::cout << calculator.evaluate(argv[1]) << std::endl;
    } catch (const std::exception &) {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    return 0;
}
