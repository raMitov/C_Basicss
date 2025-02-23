#include <iostream>
#include <vector>
#include <sstream>


void targOut(std::vector<int> &targ) {
    for (auto i : targ) {
        std::cout << i << " ";
    }
}

int main() {
    std::string input;
    std::vector<int> targets;

    std::getline(std::cin, input);
    std::istringstream iss(input);
    int num;
    while (iss >> num) {
        targets.push_back(num);
    }
    std::string shot;
    int idx;
    int shotTarget;
    while (std::cin >> shot && shot != "End") {
        idx = stoi(shot);
        if (idx < targets.size()) {
            shotTarget = targets[idx];
            targets[idx] = -1;
            for (int i = 0; i < targets.size(); i++) {
                if (targets[i] != -1) {
                    if (targets[i] > shotTarget) {
                        targets[i] -= shotTarget;
                    }
                    else if (targets[i]<= shotTarget) {
                        targets[i] += shotTarget;
                    }
                }
            }
        }
    }
    targOut(targets);
    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.