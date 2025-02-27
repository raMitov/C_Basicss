#include <iostream>
#include "SumOfVector.h"
#include <vector>

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main()
{
    int n;
    std::vector<std::string> vec;
    std::vector<int> vec_int;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::string s;
        std::cin >> s;
        vec.push_back(s);
    }
    for (int i = 0; i < n; i++) {
        int num;
        std::cin >> num;
        vec_int.push_back(num);
    }
    std::vector<std::string> result = sumVectors(n, vec, vec_int);
    for (int i = 0; i < result.size(); i++) {
        std::cout << result[i] << std::endl;
    }

    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.