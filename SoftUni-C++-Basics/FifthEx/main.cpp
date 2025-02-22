#include <iostream>
#include <string>
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main()
{
    int foodkg;
    std::cin >> foodkg;
    int foodG = foodkg * 1000;
    std::cin.ignore();
    while (true) {
        std::string input;
        getline(std::cin, input);
        if (input == "Adopted") {
            break;
        }
        else {
            int g = stoi(input);
            foodG -= g;
        }
    }
    if (foodG >= 0) {
        std::cout << "Food is enough! Leftovers: " << foodG << " grams."<< std::endl;
    }
    else {
        std::cout << "Food is not enough. You need " << abs(foodG) << " grams more." << std::endl;
    }

    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.