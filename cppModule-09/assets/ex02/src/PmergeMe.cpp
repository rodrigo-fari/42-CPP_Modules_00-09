#include "../inc/PmergeMe.hpp"

#include <climits>
#include <ctime>
#include <cctype>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdexcept>

PmergeMe::PairV::PairV() : large(0), small(0), hasSmall(false) {}

PmergeMe::PairV::PairV(int largeValue, int smallValue, bool hasSmallValue)
    : large(largeValue), small(smallValue), hasSmall(hasSmallValue) {}

PmergeMe::PairD::PairD() : large(0), small(0), hasSmall(false) {}

PmergeMe::PairD::PairD(int largeValue, int smallValue, bool hasSmallValue)
    : large(largeValue), small(smallValue), hasSmall(hasSmallValue) {}

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) : _input(other._input) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
    if (this != &other) {
        _input = other._input;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

bool PmergeMe::parsePositiveInt(const std::string &text, int &value) {
    if (text.empty()) {
        return false;
    }

    for (std::size_t i = 0; i < text.size(); ++i) {
        if (std::isdigit(static_cast<unsigned char>(text[i])) == 0) {
            return false;
        }
    }

    std::istringstream iss(text);
    long long parsed = 0;
    char extra = '\0';

    if (!(iss >> parsed) || (iss >> extra)) {
        return false;
    }
    if (parsed <= 0 || parsed > INT_MAX) {
        return false;
    }

    value = static_cast<int>(parsed);
    return true;
}

void PmergeMe::parseArguments(int argc, char **argv) {
    _input.clear();

    for (int i = 1; i < argc; ++i) {
        int number = 0;
        if (!parsePositiveInt(argv[i], number)) {
            throw std::runtime_error("Error");
        }
        _input.push_back(number);
    }

    if (_input.empty()) {
        throw std::runtime_error("Error");
    }
}

std::string PmergeMe::joinVector(const std::vector<int> &values) {
    std::ostringstream oss;
    for (std::size_t i = 0; i < values.size(); ++i) {
        if (i != 0) {
            oss << ' ';
        }
        oss << values[i];
    }
    return oss.str();
}

std::string PmergeMe::joinDeque(const std::deque<int> &values) {
    std::ostringstream oss;
    for (std::size_t i = 0; i < values.size(); ++i) {
        if (i != 0) {
            oss << ' ';
        }
        oss << values[i];
    }
    return oss.str();
}

std::vector<std::size_t> PmergeMe::buildJacobOrderVector(std::size_t count) {
    std::vector<std::size_t> order;
    if (count == 0) {
        return order;
    }

    std::size_t prevBound = 0;
    std::size_t jacPrev = 1;
    std::size_t jacCurr = 3;

    while (jacPrev <= count) {
        for (std::size_t i = jacPrev; i > prevBound; --i) {
            order.push_back(i);
        }
        prevBound = jacPrev;

        const std::size_t next = jacCurr + (2 * jacPrev);
        jacPrev = jacCurr;
        jacCurr = next;
    }

    for (std::size_t i = count; i > prevBound; --i) {
        order.push_back(i);
    }

    return order;
}

std::deque<std::size_t> PmergeMe::buildJacobOrderDeque(std::size_t count) {
    std::deque<std::size_t> order;
    if (count == 0) {
        return order;
    }

    std::size_t prevBound = 0;
    std::size_t jacPrev = 1;
    std::size_t jacCurr = 3;

    while (jacPrev <= count) {
        for (std::size_t i = jacPrev; i > prevBound; --i) {
            order.push_back(i);
        }
        prevBound = jacPrev;

        const std::size_t next = jacCurr + (2 * jacPrev);
        jacPrev = jacCurr;
        jacCurr = next;
    }

    for (std::size_t i = count; i > prevBound; --i) {
        order.push_back(i);
    }

    return order;
}

void PmergeMe::binaryInsertVector(std::vector<int> &chain, int value) {
    std::size_t left = 0;
    std::size_t right = chain.size();

    while (left < right) {
        const std::size_t mid = left + (right - left) / 2;
        if (chain[mid] < value) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    chain.insert(chain.begin() + static_cast<std::vector<int>::difference_type>(left), value);
}

void PmergeMe::binaryInsertDeque(std::deque<int> &chain, int value) {
    std::size_t left = 0;
    std::size_t right = chain.size();

    while (left < right) {
        const std::size_t mid = left + (right - left) / 2;
        if (chain[mid] < value) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    chain.insert(chain.begin() + static_cast<std::deque<int>::difference_type>(left), value);
}

void PmergeMe::sortPairsVector(std::vector<PairV> &pairs) {
    if (pairs.size() <= 1) {
        return;
    }

    const std::size_t mid = pairs.size() / 2;
    std::vector<PairV> left(pairs.begin(), pairs.begin() + static_cast<std::vector<PairV>::difference_type>(mid));
    std::vector<PairV> right(pairs.begin() + static_cast<std::vector<PairV>::difference_type>(mid), pairs.end());

    sortPairsVector(left);
    sortPairsVector(right);

    std::size_t i = 0;
    std::size_t j = 0;
    std::size_t k = 0;

    while (i < left.size() && j < right.size()) {
        if (left[i].large <= right[j].large) {
            pairs[k++] = left[i++];
        } else {
            pairs[k++] = right[j++];
        }
    }
    while (i < left.size()) {
        pairs[k++] = left[i++];
    }
    while (j < right.size()) {
        pairs[k++] = right[j++];
    }
}

void PmergeMe::sortPairsDeque(std::deque<PairD> &pairs) {
    if (pairs.size() <= 1) {
        return;
    }

    const std::size_t mid = pairs.size() / 2;
    std::deque<PairD> left(pairs.begin(), pairs.begin() + static_cast<std::deque<PairD>::difference_type>(mid));
    std::deque<PairD> right(pairs.begin() + static_cast<std::deque<PairD>::difference_type>(mid), pairs.end());

    sortPairsDeque(left);
    sortPairsDeque(right);

    std::size_t i = 0;
    std::size_t j = 0;
    std::size_t k = 0;

    while (i < left.size() && j < right.size()) {
        if (left[i].large <= right[j].large) {
            pairs[k++] = left[i++];
        } else {
            pairs[k++] = right[j++];
        }
    }
    while (i < left.size()) {
        pairs[k++] = left[i++];
    }
    while (j < right.size()) {
        pairs[k++] = right[j++];
    }
}

std::vector<int> PmergeMe::fordJohnsonVector(const std::vector<int> &values) {
    if (values.size() <= 1) {
        return values;
    }

    std::vector<PairV> pairs;
    pairs.reserve((values.size() + 1) / 2);

    for (std::size_t i = 0; i < values.size(); i += 2) {
        if (i + 1 < values.size()) {
            const int a = values[i];
            const int b = values[i + 1];
            if (a >= b) {
                pairs.push_back(PairV(a, b, true));
            } else {
                pairs.push_back(PairV(b, a, true));
            }
        } else {
            pairs.push_back(PairV(values[i], 0, false));
        }
    }

    std::vector<int> mainValues;
    mainValues.reserve(pairs.size());
    for (std::size_t i = 0; i < pairs.size(); ++i) {
        mainValues.push_back(pairs[i].large);
    }

    const std::vector<int> sortedMain = fordJohnsonVector(mainValues);

    std::vector<PairV> orderedPairs;
    orderedPairs.reserve(pairs.size());
    std::vector<int> used(pairs.size(), 0);
    for (std::size_t i = 0; i < sortedMain.size(); ++i) {
        for (std::size_t j = 0; j < pairs.size(); ++j) {
            if (used[j] == 0 && pairs[j].large == sortedMain[i]) {
                orderedPairs.push_back(pairs[j]);
                used[j] = 1;
                break;
            }
        }
    }
    pairs.swap(orderedPairs);

    std::vector<int> chain;
    chain.reserve(values.size());

    for (std::size_t i = 0; i < pairs.size(); ++i) {
        chain.push_back(pairs[i].large);
    }

    if (!pairs.empty() && pairs[0].hasSmall) {
        binaryInsertVector(chain, pairs[0].small);
    }

    std::vector<int> pending;
    for (std::size_t i = 1; i < pairs.size(); ++i) {
        if (pairs[i].hasSmall) {
            pending.push_back(pairs[i].small);
        }
    }

    const std::vector<std::size_t> order = buildJacobOrderVector(pending.size());
    for (std::size_t i = 0; i < order.size(); ++i) {
        const std::size_t index = order[i] - 1;
        binaryInsertVector(chain, pending[index]);
    }

    return chain;
}

std::deque<int> PmergeMe::fordJohnsonDeque(const std::deque<int> &values) {
    if (values.size() <= 1) {
        return values;
    }

    std::deque<PairD> pairs;

    for (std::size_t i = 0; i < values.size(); i += 2) {
        if (i + 1 < values.size()) {
            const int a = values[i];
            const int b = values[i + 1];
            if (a >= b) {
                pairs.push_back(PairD(a, b, true));
            } else {
                pairs.push_back(PairD(b, a, true));
            }
        } else {
            pairs.push_back(PairD(values[i], 0, false));
        }
    }

    std::deque<int> mainValues;
    for (std::size_t i = 0; i < pairs.size(); ++i) {
        mainValues.push_back(pairs[i].large);
    }

    const std::deque<int> sortedMain = fordJohnsonDeque(mainValues);

    std::deque<PairD> orderedPairs;
    std::deque<int> used(pairs.size(), 0);
    for (std::size_t i = 0; i < sortedMain.size(); ++i) {
        for (std::size_t j = 0; j < pairs.size(); ++j) {
            if (used[j] == 0 && pairs[j].large == sortedMain[i]) {
                orderedPairs.push_back(pairs[j]);
                used[j] = 1;
                break;
            }
        }
    }
    pairs.swap(orderedPairs);

    std::deque<int> chain;
    for (std::size_t i = 0; i < pairs.size(); ++i) {
        chain.push_back(pairs[i].large);
    }

    if (!pairs.empty() && pairs[0].hasSmall) {
        binaryInsertDeque(chain, pairs[0].small);
    }

    std::deque<int> pending;
    for (std::size_t i = 1; i < pairs.size(); ++i) {
        if (pairs[i].hasSmall) {
            pending.push_back(pairs[i].small);
        }
    }

    const std::deque<std::size_t> order = buildJacobOrderDeque(pending.size());
    for (std::size_t i = 0; i < order.size(); ++i) {
        const std::size_t index = order[i] - 1;
        binaryInsertDeque(chain, pending[index]);
    }

    return chain;
}

void PmergeMe::process() const {
    std::cout << "Before: " << joinVector(_input) << std::endl;

    const std::clock_t vectorStart = std::clock();
    std::vector<int> vectorData(_input.begin(), _input.end());
    const std::vector<int> sortedVector = fordJohnsonVector(vectorData);
    const std::clock_t vectorEnd = std::clock();

    const std::clock_t dequeStart = std::clock();
    std::deque<int> dequeData(_input.begin(), _input.end());
    const std::deque<int> sortedDeque = fordJohnsonDeque(dequeData);
    const std::clock_t dequeEnd = std::clock();

    std::cout << "After: " << joinVector(sortedVector) << std::endl;

    const double vectorUs = (static_cast<double>(vectorEnd - vectorStart) * 1000000.0) / CLOCKS_PER_SEC;
    const double dequeUs = (static_cast<double>(dequeEnd - dequeStart) * 1000000.0) / CLOCKS_PER_SEC;

    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Time to process a range of " << _input.size()
              << " elements with std::vector : " << vectorUs << " us" << std::endl;
    std::cout << "Time to process a range of " << _input.size()
              << " elements with std::deque : " << dequeUs << " us" << std::endl;

    if (joinVector(sortedVector) != joinDeque(sortedDeque)) {
        throw std::runtime_error("Error");
    }
}
