#include "Yoshi.h"

std::string Yoshi::WhatAmI() const{
  std::string name="Yoshi";
  return name;
}

void Yoshi::Accelerate(){
  if(this->_speed<this->_max_speed){
    Character::Accelerate();
    Character::Accelerate();
  }
}
