//
// Created by garjo on 2/27/25.
//
#include "Student.h"
#include "Discipline.h"
#include <iostream>
#include <string>

Student::Student(std::string nam, long int facultyNume):name(nam),facultyNumber(facultyNume){}
void Student::addDiscipline(const Discipline & discipline, int grade){
  	disciplines.insert({discipline, grade});
}
int Student::attendedDisciplines(){
  int count = 0;
  for(auto it = disciplines.begin(); it != disciplines.end(); it++){
    count++;
  }
  return count;
}
void Student::printDisciplines(){
  for (const auto & it : disciplines){
    std::cout << it.first.getName() << " ";
  }
  std::cout << std::endl;
}
int Student::GetGrade(std::string disciplineName){
	for(const auto & it : disciplines){
          std::string tmp = it.first.getName();
          if(it.first.getName() == disciplineName){
            return it.second;
          }
	}
}
double Student::GetAvgGrade(){
  double sum = 0;
	for(const auto & it : disciplines){
          sum += it.second;
	}
        return sum / disciplines.size();
}
void Student::printStudent(){
	std::cout << "Student name: "<< name << std::endl;
    std::cout << "Student faculty number: " << facultyNumber << std::endl;
    for(const auto & it : disciplines){
      std::cout << "Discipline: "<<it.first.getName() << " Grade: " << it.second << std::endl;
    }
}