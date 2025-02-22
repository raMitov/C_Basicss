#include <iostream>
#include <string>
#include <iomanip>
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    std::string fruit;
    std::string size;
    int count;
    std::cin >> fruit >> size >> count;
    double price = 0;
    if (fruit == "Watermelon" && size == "small") {
        price = (56 * 2) * count * 1.0;
    }
    else if (fruit == "Watermelon" && size == "big") {
        price = (28.70 * 5) * count * 1.0;
    }
    if (fruit == "Mango" && size == "small") {
        price = (36.66 * 2) * count * 1.0;
    }
    else if (fruit == "Mango" && size == "big") {
        price = (19.60 * 5) * count * 1.0;
    }
    if (fruit == "Pineapple" && size == "small") {
        price = (42.10 * 2) * count * 1.0;
    }
    else if (fruit == "Pineapple" && size == "big") {
        price =  (24.80 * 5) * count * 1.0;
    }
    if (fruit == "Raspberry" && size == "small") {
        price = (20 * 2) * count * 1.0;
    }
    else if (fruit == "Raspberry" && size == "big") {
        price = (15.20 * 5) * count * 1.0;
    }
    if (price >= 400 && price <= 1000) {
        price -= price * 0.15;
    }
    else if (price > 1000) {
        price -= price * 0.5;
    }

    std::cout << std::fixed << std::setprecision(2);
    std::cout << price << " lv."<< std::endl;
    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.