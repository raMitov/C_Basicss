#include <charconv>
#include <iostream>
#include <string>
#include <iomanip>
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    int n;
    std::cin >> n;
    std::cin.ignore();
    double moneyWon = 0;
    int WinLossBalance = 0;
    while (n > 0) {
        int dailyWinLoss = 0;
        int dailyMoneyWon = 0;
        std::string game;
        std::cin >> game;
        while (game != "Finish") {
            if (game == "win") {
                dailyMoneyWon += 20;
                WinLossBalance++;
                dailyWinLoss++;
            }
            else if (game == "lose") {
                WinLossBalance--;
                dailyWinLoss--;
            }
            std::cin >> game;
            if (game == "Finish") {
                n--;
                break;
            }
        }
        if (dailyWinLoss > 0) {
            moneyWon += dailyMoneyWon + (dailyMoneyWon * 0.1);
        }
        else {
            moneyWon += dailyMoneyWon;
        }
    }
    std::cout << std::fixed << std::setprecision(2);
    if (WinLossBalance > 0) {
        moneyWon += moneyWon * 0.2;
        std::cout << "You won the tournament! Total raised money:  " << moneyWon << std::endl;
    }
    else {
        std::cout << "the tournament! Total raised money:   " << moneyWon << std::endl;
    }


    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.