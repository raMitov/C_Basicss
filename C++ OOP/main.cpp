#include <iostream>
#include "Car.h"
#include <string>
#include <sstream>

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    std::string input;
    std::getline(std::cin, input);
    std::istringstream iss(input);
    std::string year;
    Car car6;

    Car car("gei", "neiko", "gei");
    Car car2("gei", "Krusto", "gei");

    std::cout << "Brand ->" << car.getBrand() << std::endl;
    std::cout << "Model ->" << car.getModel() << std::endl;
    std::cout << "Year ->" << car.getYear() << std::endl;
    std::cout << std::endl;
    std::cout << "Brand ->" << car2.getBrand() << std::endl;
    std::cout << "Model ->" << car2.getModel() << std::endl;
    std::cout << "Year ->" << car2.getYear() << std::endl;
    Car car3;
    car3.setBrand("Mersi");
    car3.setModel("Neiko");
    car3.setYear("2006");
    std::cout << "Brand ->" << car3.getBrand() << std::endl;
    std::cout << "Model ->" << car3.getModel() << std::endl;
    std::cout << "Year ->" << car3.getYear() << std::endl;
    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.