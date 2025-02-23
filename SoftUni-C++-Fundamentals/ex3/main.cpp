#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
double findAvg(std::vector<int> &v) {
    int sum = 0;
    for (const int i : v) {
        sum += i;
    }
    const double avg = (1.0 * sum) / v.size();
    return avg;
}
void findBiggerThanAvg(std::vector<int> &v, const double &avg) {
    std::vector<int> greaterThanAvg;
    for (const int i : v) {
        if (i > avg) {
            greaterThanAvg.push_back(i);
        }
    }
    if (greaterThanAvg.empty()) {
        std::cout << "No" << std::endl;
    }
    std::sort(greaterThanAvg.begin(), greaterThanAvg.end(), std::greater<int>());

    for (size_t i = 0; i < std::min(greaterThanAvg.size(), size_t(5)); ++i) {
        std::cout << greaterThanAvg[i] << " ";
    }
    std::cout << std::endl;

}
int main()
{
    std::string input;
    std::getline(std::cin, input);
    std::istringstream iss(input);
    int  number;
    std::vector <int> numbers;
    while (iss >> number) {
        numbers.push_back(number);
    }
    if (numbers.empty() || numbers.size() == 1) {
        std::cout << "No" << std::endl;
        return 0;
    }

    const double avg = findAvg(numbers);
    findBiggerThanAvg(numbers, avg);
    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.