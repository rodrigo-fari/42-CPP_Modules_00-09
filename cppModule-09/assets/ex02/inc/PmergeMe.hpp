#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <string>
#include <vector>

class PmergeMe {
public:
    PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    ~PmergeMe();

    void parseArguments(int argc, char **argv);
    void process() const;

private:
    struct PairV {
        int large;
        int small;
        bool hasSmall;

        PairV();
        PairV(int largeValue, int smallValue, bool hasSmallValue);
    };

    struct PairD {
        int large;
        int small;
        bool hasSmall;

        PairD();
        PairD(int largeValue, int smallValue, bool hasSmallValue);
    };

    std::vector<int> _input;

    static bool parsePositiveInt(const std::string &text, int &value);
    static std::string joinVector(const std::vector<int> &values);
    static std::string joinDeque(const std::deque<int> &values);

    static std::vector<std::size_t> buildJacobOrderVector(std::size_t count);
    static std::deque<std::size_t> buildJacobOrderDeque(std::size_t count);

    static void binaryInsertVector(std::vector<int> &chain, int value);
    static void binaryInsertDeque(std::deque<int> &chain, int value);

    static void sortPairsVector(std::vector<PairV> &pairs);
    static void sortPairsDeque(std::deque<PairD> &pairs);

    static std::vector<int> fordJohnsonVector(const std::vector<int> &values);
    static std::deque<int> fordJohnsonDeque(const std::deque<int> &values);
};

#endif
