#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
bool isSeparator(char c) {
    return std::isspace(c) || std::ispunct(c);
}
bool compareWords(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
    if (a.second != b.second) {
        return a.second > b.second;
    }
    return a.first < b.first;
}

int main() {
    std::string line;
    std::getline(std::cin, line);

    for (char& c : line) {
        if (isSeparator(c)) {
            c = ' ';
        }
        else if (isupper(c)) {
            c = tolower(c);
        }
    }
    std::map<std::string, int> words;
    std::istringstream iss(line);
    std::string word;
    while (iss >> word) {
        words[word]++;
    }
    std::vector<std::pair<std::string, int>> wordsList(words.begin(), words.end());
    std::sort(wordsList.begin(), wordsList.end(), compareWords);

    for (const auto& pair : wordsList) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.