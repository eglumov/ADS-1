// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"

bool checkPrime(uint64_t value) {
    if (value <= 1) {
        return false;
    }
    if (value <= 3) {
        return true;
    }
    if (value % 2 == 0 || value % 3 == 0) {
        return false;
    }
    for (uint64_t i = 5; i * i <= value; i += 6) {
        if (value % i == 0 || value % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

uint64_t nPrime(uint64_t n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 2;
    }
    uint64_t primeCount = 1;
    uint64_t candidate = 3;
    while (true) {
        if (checkPrime(candidate)) {
            primeCount++;
            if (primeCount == n) {
                return candidate;
            }
        }
        candidate += 2;
    }
}

uint64_t nextPrime(uint64_t value) {
    if (value < 2) {
        return 2;
    }
    uint64_t candidate = (value % 2 == 0) ? value + 1 : value + 2;
    while (!checkPrime(candidate)) {
        candidate += 2;
    }
    return candidate;
}

uint64_t sumPrime(uint64_t hbound) {
    if (hbound <= 2) {
        return 0;
    }
    uint64_t totalSum = 2;
    for (uint64_t i = 3; i < hbound; i += 2) {
        if (checkPrime(i)) {
            totalSum += i;
        }
    }
    return totalSum;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
    if (hbound < 3) {
        return 0;
    }
    uint64_t twinPairsCount = 0;
    uint64_t startOdd = (lbound < 3) ? 3 : lbound;
    if (start_odd % 2 == 0) {
        startOdd++;
    }
    for (uint64_t i = startOdd; i + 2 < hbound; i += 2) {
        if (checkPrime(i) && checkPrime(i + 2)) {
            twinPairsCount++;
        }
    }
    return twinPairsCount;
}
