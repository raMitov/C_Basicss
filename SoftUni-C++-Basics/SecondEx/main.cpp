#include <iostream>

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    int minutesWalking;
    int walksCount;
    int calorieIntake;
    std:: cin >> minutesWalking >> walksCount >> calorieIntake;
    int caloriesPerMin = 5;
    int caloriesBurned = (minutesWalking * caloriesPerMin) * walksCount;
    if (caloriesBurned >= calorieIntake / 2) {
        std::cout << "Yes, the walk for your cat is enough. Burned calories per day: " << caloriesBurned << std::endl;
    }
    else {
        std::cout << "No, the walk for your cat is not enough. Burned calories per day: " << caloriesBurned << std::endl;
    }
    return 0;
}
// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.