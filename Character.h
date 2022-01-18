#ifndef DEF_PERSONNAGE
#define DEF_PERSONNAGE

#include <iostream>
#include <string>

class Character{
protected:
  float _speed;
  float _max_speed;
public:
  Character();
  ~Character()=default;
  void Accelerate();
  void Break();
  inline float speed() const{
    return _speed;
  }
  virtual std::string WhatAmI() const = 0;
};

#endif
