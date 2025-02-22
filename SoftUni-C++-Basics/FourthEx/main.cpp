#include <iostream>
#include <iomanip>
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main()
{
    int groupCount;
    std::cin >> groupCount;
    int musala = 0, monblan = 0, kilimanjaro = 0, k2 = 0, everest = 0;
    for (int i = 0; i < groupCount; i++) {
        int group;
        std::cin >> group;
        if (group <= 5) {
            musala += group;
        }
        else if (group <= 12) {
            monblan += group;
        }

        else if (group <= 25) {
            kilimanjaro += group;
        }

        else if (group <= 40) {
            k2+= group;
        }
        else {
            everest += group;
        }
    }
    int allPeople = musala + monblan + kilimanjaro + k2 + everest;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Musala climbers: " << (musala * 100.0) / allPeople<< "%" << std::endl;
    std::cout << "Monblan climbers: " << (monblan * 100.0)/ allPeople<<"%"<< std::endl;
    std::cout << "Kilimanjaro climbers: "<< (kilimanjaro* 100.0) / allPeople<<"%"<< std::endl;
    std::cout << "K2 climbers: "<< (k2*100.0) / allPeople << "%"<< std::endl;
    std::cout << "Everest climbers: " << (everest*100.0) / allPeople << "%"<< std::endl;
    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.