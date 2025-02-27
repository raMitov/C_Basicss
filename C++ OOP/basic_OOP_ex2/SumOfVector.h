//
// Created by garjo on 2/27/25.
//
#include <vector>
#ifndef SUMOFVECTOR_H
#define SUMOFVECTOR_H

std::vector<std::string> sumVectors(const int n, const std::vector<std::string> &vec1, const std::vector<int> &vec2) {
    std::vector<std::string> result;
    result.reserve(n);
    for (int i = 0; i < n; i++) {
        std::string tmp = vec1[i] + " " + std::to_string(vec2[i]);
        result.push_back(tmp);
    }
    return result;
}

#endif //SUMOFVECTOR_H
