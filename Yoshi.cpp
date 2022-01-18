#include "Yoshi.h"

Yoshi::Yoshi(int nbCrests){
  this->_nbCrests=nbCrests;
}

std::string Yoshi::WhatAmI() const{
  char crests[10];
  sprintf(crests,"%d",this->_nbCrests);
  std::string crests_s(crests);
  std::string endSentence(" crested Yoshi");
  std::string name=crests+endSentence;
  return name;
}

void Yoshi::Accelerate(){
  if(this->_speed<this->_max_speed){
    Character::Accelerate();
    Character::Accelerate();
  }
}
