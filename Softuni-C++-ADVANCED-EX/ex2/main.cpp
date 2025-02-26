#include <iostream>
#include <vector>
#include <string>
#include <map>
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    std::vector<char> galaxy;
    std::string input;
    std::map<char, int> stars;
    int starcount = 0;
    while (getline(std::cin, input) && input != "end") {
        for (int i = 0; i < input.size(); i++) {
            galaxy.push_back(input[i]);
        }

    }
    int planetsCount = 0;
    int asteroidCometCount = 0;
    for (int i = 0; i < galaxy.size(); i++) {
        if (galaxy[i] >= 65 && galaxy[i]<= 90) {
            stars[galaxy[i]]++;
            starcount++;
        }
        else if (galaxy[i] == '1' || galaxy[i] == '2' ||  galaxy[i] == '3' || galaxy[i] == '4' || galaxy[i] == '5' || galaxy[i] == '6'  || galaxy[i] == '7' || galaxy[i] == '8'  || galaxy[i] == '9') {
            planetsCount += (galaxy[i] - '0');
        }
        else if (galaxy[i] == '#' ||  galaxy[i] == '$') {
            asteroidCometCount++;
        }

    }

    std::string word;
    std::cin >> word;
    for (int i = 0; i < word.size(); i++) {
        for (int j = 0; j < galaxy.size(); j++) {
            if (galaxy[j] == word[i]) {
                galaxy[j] = '+';
            }
        }
    }
    std::cout << "Stars: " << starcount << std::endl;
    for (const auto &p : stars) {
        std::cout << "- "<< p.first << ": " << p.second << std::endl;
    }
    std::cout << "Planets: " << planetsCount << std::endl;
    std::cout << "Asteroids/comets: " << asteroidCometCount << std::endl;
    int outputCount = galaxy.size() / 3;
    int helper = outputCount;
    for (int i = 0; i < galaxy.size(); i++) {
        std::cout << galaxy[i];
        outputCount--;
        if (outputCount == 0) {
            std::cout << std::endl;
            outputCount = helper;
        }
    }
    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.