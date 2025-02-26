#include <iostream>
#include <queue>
#include <stack>
#include <sstream>
#include <string>
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    std::queue<std::string> flowA;
    std::stack<std::string> flowB;
    std::string input;
    while (std::cin >> input && input != "end") {
        std::string flow;
        std::cin >> flow;
        if (flow == "A") {
            flowA.push(input);
        }
        else if (flow == "B") {
            flowB.push(input);
        }
    }
    std::cout << "Flow A:" << std::endl;
    if (!flowA.empty()) {
        while (!flowA.empty()) {
            std::cout << flowA.front();
            flowA.pop();
            if (!flowA.empty()) {
                std::cout << ", ";
            }
        }
    }
    else {
        std::cout << "<EMPTY>" << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Flow B:" << std::endl;
    if (!flowB.empty()) {
        while (!flowB.empty()) {
            std::cout << flowB.top();
            flowB.pop();
            if (!flowB.empty()) {
                std::cout << ", ";
            }
        }
    }
    else {
        std::cout << "<EMPTY>" << std::endl;
    }

    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.