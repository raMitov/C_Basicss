#ifndef OPERATORS_H

#define OPERATORS_H
#include <ostream>
#include <vector>
#include <string>
#include <sstream>

std::vector<std::string> & operator << (std::vector<std::string> & vec,  const std::string & str) {
    vec.push_back(str);
    return vec;
}
std::string operator + (std::string & str1,  std::string & str2) {
    std::ostringstream ss;
    ss << str1 << str2;
    return ss.str();
}
std::string & operator + (std::string & str1, int n) {
    str1 = str1 + std::to_string(n);
    return str1;
}

std::ostream & operator << (std::ostream & os, const std::vector<std::string> & vec) {
    for (const auto & i : vec) {
        os << i << std::endl;
    }
    return os;
}



#endif // !OPERATORS_H