//
// Created by garjo on 2/27/25.
//
#include <iostream>
#include "Discipline.h"

Discipline::Discipline(std::string disciplineName): name(disciplineName){}
std::string Discipline::getName() const{
  return name;
}