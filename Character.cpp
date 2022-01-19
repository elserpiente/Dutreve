#include "Character.h"

Character::Character(){
  //default constructor
  this->_speed=0;
  this->_max_speed=10;
}

void Character::Accelerate(){
  //We check if the speed is maxed and increment it if not
  if(this->_speed<this->_max_speed){
    this->_speed++;
  }
}

void Character::Break(){
  //We check if the speed is null and decrement it if not
  if(this->_speed>0){
    this->_speed--;
  }
}
