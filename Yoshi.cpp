#include "Yoshi.h"

Yoshi::Yoshi(int nbCrests){
  //New constructor
  this->_nbCrests=nbCrests;
}

std::string Yoshi::WhatAmI() const{
  //First we transform the int number of crests in char table
  char crests[10];
  sprintf(crests,"%d",this->_nbCrests);
  //Then we made a string out of it to allowd concatenation
  std::string crests_s(crests);
  std::string endSentence(" crested Yoshi");
  std::string name=crests+endSentence;
  //Finaly we return the concatenation
  return name;
}

void Yoshi::Accelerate(){
  //Pretty similar to the Character.cpp one but with to incrementations insted of one
  if(this->_speed<this->_max_speed){
    Character::Accelerate();
    Character::Accelerate();
  }
}
