#include "../inc/RPN.hpp"

#include <cctype>
#include <sstream>
#include <stdexcept>

RPN::RPN() {}

RPN::RPN(const RPN &other) : _stack(other._stack) {}

RPN &RPN::operator=(const RPN &other) {
    if (this != &other) {
        _stack = other._stack;
    }
    return *this;
}

RPN::~RPN() {}

bool RPN::isOperatorToken(const std::string &token) {
    return token.size() == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/');
}

long RPN::applyOperator(char op, long lhs, long rhs) const {
    if (op == '+') {
        return lhs + rhs;
    }
    if (op == '-') {
        return lhs - rhs;
    }
    if (op == '*') {
        return lhs * rhs;
    }
    if (rhs == 0) {
        throw std::runtime_error("Error");
    }
    return lhs / rhs;
}

void RPN::applyToken(const std::string &token) {
    if (token.size() == 1 && std::isdigit(static_cast<unsigned char>(token[0])) != 0) {
        _stack.push_back(token[0] - '0');
        return;
    }

    if (!isOperatorToken(token)) {
        throw std::runtime_error("Error");
    }

    if (_stack.size() < 2) {
        throw std::runtime_error("Error");
    }

    const long rhs = _stack.back();
    _stack.pop_back();
    const long lhs = _stack.back();
    _stack.pop_back();

    _stack.push_back(applyOperator(token[0], lhs, rhs));
}

long RPN::evaluate(const std::string &expression) {
    _stack.clear();

    std::istringstream iss(expression);
    std::string token;
    bool hasToken = false;

    while (iss >> token) {
        hasToken = true;
        applyToken(token);
    }

    if (!hasToken || _stack.size() != 1) {
        throw std::runtime_error("Error");
    }

    return _stack.back();
}
