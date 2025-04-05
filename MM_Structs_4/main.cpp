#include <iostream>
#include <vector>
struct Adress {
    char city[32];
    unsigned int postal_code;
    char street[64];
};
struct Student {
    char first_name[32];
    char middle_name[32];
    char last_name[32];
    Adress adress;
    char facultyNum[10];
    char email[32];
    int course;
    int potok;
    int group;
    int passed_exams;
    std::vector<int> grades;
};

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {


    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.