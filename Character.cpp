#include "Character.h"

Character::Character(){
  this->_speed=0;
  this->_max_speed=10;
}

void Character::Accelerate(){
  if(this->_speed<this->_max_speed){
    this->_speed++;
  }
}

void Character::Break(){
  if(this->_speed>0){
    this->_speed--;
  }
}
