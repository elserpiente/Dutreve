#include "Character.h"

Character::Character(){
  this->_speed=0;
  this->_max_speed=10;
}

void Character::Accelerate(){
  this->_speed++;
}

void Character::Break(){
  this->_speed--;
}
