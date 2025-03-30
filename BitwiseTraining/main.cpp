#include <iostream>
#include <climits>
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
void clearBit(int &number, const int index) {
    number = number & ~(1 << index);
}
void toggleBit(int &number, const int index) {
    number = number ^ (1 << index);
}
//Reverse the bits of an unsigned integer meaning toggle them
void reverseBits(unsigned int &number) {
    constexpr int BITS_IN_UINT = sizeof(unsigned int) * CHAR_BIT;
    for (int i = 0; i < BITS_IN_UINT; i++) {
        number = number ^ (1 << i);
    }
}
//count set bits of an int
int countSetBits(int number) {
    int count = 0;
    constexpr int SET_BITS = sizeof(int) * CHAR_BIT;
    for (int i = 0; i < SET_BITS; i++) {
        if (number & (1 << i)) {
            count++;
        }
    }
    return count;
}
int main() {

    int checkNumber;
    std::cin >> checkNumber;
    // isEvenOrOdd(checkNumber);
    // setBit(checkNumber, 4);
    // std::cout << checkNumber << std::endl;
    // clearBit(checkNumber, 5);
    // std::cout << checkNumber << std::endl;
    // toggleBit(checkNumber, 4);
    // std::cout << checkNumber << std::endl;
    unsigned int newNumber = 288;
    std::cout << newNumber << std::endl;
    reverseBits(newNumber);
    std::cout << newNumber << std::endl;
    std::cout << countSetBits(checkNumber) << std::endl;
    return 0;

}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.