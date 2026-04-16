#ifndef RPN_HPP
#define RPN_HPP

#include <list>
#include <string>

class RPN {
public:
    RPN();
    RPN(const RPN &other);
    RPN &operator=(const RPN &other);
    ~RPN();

    long evaluate(const std::string &expression);

private:
    std::list<long> _stack;

    static bool isOperatorToken(const std::string &token);
    long applyOperator(char op, long lhs, long rhs) const;
    void applyToken(const std::string &token);
};

#endif
