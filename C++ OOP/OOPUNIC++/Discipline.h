//
// Created by garjo on 2/27/25.
//

#ifndef DISCIPLINE_H
#define DISCIPLINE_H
#include <string>


class Discipline {


  public:
    Discipline() = default;
    Discipline(std::string disciplineName);
    bool operator<(const Discipline& other) const {
        return name < other.name;  // Sorts disciplines alphabetically
    }
    std::string name;
    std::string getName() const;
};



#endif //DISCIPLINE_H
