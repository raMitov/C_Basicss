#include <cstring>
#include <iostream>


enum color {
    yellow,
    green,
    orange,
    red,
    brown
};
const char* colorToStr(color c) {
    switch(c) {
        case yellow: return "yellow";
        case green: return "green";
        case orange: return "orange";
        case red: return "red";
        case brown: return "brown";
        default: return "unknown";
    }
}

color strToColor(const char *str) {
    if (strcmp("yellow", str) == 0) return color::yellow;
    if (strcmp("green", str) == 0) return color::green;
    if (strcmp("orange", str) == 0) return color::orange;
    if (strcmp("red", str) == 0) return color::red;
    return color::brown;
}
enum yn {
    Yes,
    No

};
const char* ynToStr(yn y) {
    return y == Yes ? "Yes" : "No";
}
yn strToYn(const char* str) {
    if (strcmp(str, "Yes") == 0 || strcmp(str, "yes") == 0 || strcmp(str, "Y") == 0 || strcmp(str, "y") == 0)
        return Yes;
    return No;
}
struct Fruit {
    char name[32];
    color cl;
    yn annual;
    yn perennial;
    yn tropical;
};
void printFruits(const Fruit* const fruits[], const int size) {
    for (int i = 0; i < size; i++) {
        std::cout << fruits[i]->name << " ";
        std::cout << colorToStr(fruits[i]->cl) << " ";
        std::cout << ynToStr(fruits[i]->annual) << " ";
        std::cout << ynToStr(fruits[i]->perennial) << " ";
        std::cout << ynToStr(fruits[i]->tropical) << std::endl;
    }
}

void SortFtuirsByColor(Fruit* fruits[], const int size, std::string color) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (color == colorToStr(fruits[i]->cl) && fruits[i]->annual == 0) {
            count++;
        }
    }
    Fruit fr[count];
    for (int i = 0; i < count; i++) {
        if (color == colorToStr(fruits[i]->cl) && fruits[i]->annual == 0) {
            fr[i] = *fruits[i];
        }
    }
    for (int i = 0; i < count; i++) {
        for (int j = i+1; j < size; j++) {
            if (fr[i].name < fr[j].name) {
                Fruit temp = fr[i];
                fr[i] = fr[j];
                fr[j] = temp;
            }
        }
    }
    for (int i = 0; i < count; i++) {
        std::cout << fr[i].name << " ";
        std::cout << colorToStr(fr[i].cl) << " ";
        std::cout << ynToStr(fr[i].annual) << " ";
        std::cout << ynToStr(fr[i].perennial) << " ";
        std::cout << ynToStr(fr[i].tropical) << std::endl;
    }

}
int main() {
    int n;
    std::cout << "Enter number of fruits: ";
    std::cout << std::endl;
    std::cin >> n;
    std::cin.ignore();
    Fruit* fruits[n];
    for (int i = 0; i < n; i++) {
        fruits[i] = new Fruit;
        std::cout << "Enter fruit name: ";
        std::cin.getline(fruits[i]->name, 32);
        std::cout << "Enter fruit color: (yellow, green, brown, red, orange)";
        char colorStr[10];
        std::cin.getline(colorStr, 10);
        fruits[i]->cl = strToColor(colorStr);
        std::cout << "Enter fruit annual: yes/no ";
        char ynStr[4];
        std::cin.getline(ynStr, 4);
        fruits[i]->annual = strToYn(ynStr);
        std::cout << "Enter fruit perenial: yes/no ";
        char perenStr[4];
        std::cin.getline(perenStr, 4);
        fruits[i]->perennial = strToYn(perenStr);
        std::cout << "Enter fruit tropical: yes/no ";
        char tropicalStr[4];
        std::cin.getline(tropicalStr, 4);
        fruits[i]->tropical = strToYn(tropicalStr);
    }
    printFruits(fruits, n);
    for (int i = 0; i < n; i++) {
        delete fruits[i];
    }
    delete[] fruits;
    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.