#include <utility>

//
// Created by garjo on 2/26/25.
//

#ifndef CAR_H
#define CAR_H

class Car {

    public:
    Car() = default;
    Car(std::string brand, std::string model, std::string year) {
        this->brand = std::move(brand);
        this->model = std::move(model);
        this->year = std::move(year);
    }
    std::string getBrand() {
      return this->brand;
    }
    std::string getModel() {
        return this->model;
    }
    std::string getYear() {
        return this->year;
    }
    void setBrand(const std::string &brand) {
        this->brand = brand;
    }
    void setModel(const std::string &model) {
        this->model = model;
    }
    void setYear(const std::string &year) {
        this->year = year;
    }
    private:
    std::string brand;
    std::string model;
    std::string year;

};


#endif //CAR_H
