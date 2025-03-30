#include <iostream>

void isEvenOrOdd(const int number) {
    if ((number & 1) == 0) {
        std::cout << number << " is even" << std::endl;
    }
    else {
        std::cout << number << " is odd" << std::endl;
    }
}
//sets the bit by index
void setBit(int &number, const int index) {
    number = number | (1 << index);
}
int main() {

    int checkNumber;
    std::cin >> checkNumber;
    isEvenOrOdd(checkNumber);
    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.