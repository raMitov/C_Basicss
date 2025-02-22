#include <iostream>
int main() {
    int rent;
    std::cin >> rent;
    double cake = rent * 0.2;
    double drinks = cake - (cake * 0.45);
    double animator = rent / 3.0;
    double price = rent + cake + drinks + animator;
    std::cout << price << std::endl;

    return 0;
}
