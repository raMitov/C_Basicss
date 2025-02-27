//
// Created by garjo on 2/27/25.
//

#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <map>
#include "Discipline.h"

class Student{
  public:

    Student(std::string name, long int facultyNumber);
    void addDiscipline(const Discipline & discipline, int grade);
    int attendedDisciplines();
    void printDisciplines();
    int GetGrade(std::string disciplineName);
    double GetAvgGrade();
    void printStudent();

  private:
  std::string name;
  long int facultyNumber;
  std::map<Discipline, int> disciplines;

};

#endif //STUDENT_H
