#include <iostream>
#include <string>


// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    std::string message;
    std::getline(std::cin, message);
    int ascisum = 0;
    for (auto c : message) {
        if (isdigit(c)) {
            ascisum += (c - '0');
        }
    }
    char result_char = static_cast<char>(ascisum);
    if (ascisum < 31) {
        std::cout << ascisum<< std::endl;

    }
    else {
        std::cout << result_char << std::endl;
    }
    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.