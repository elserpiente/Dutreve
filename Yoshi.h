#include "Character.h"

class Yoshi : public Character{
protected:
  //An attribute found only in Yoshi's objects
  int _nbCrests;
public:
  //New Yoshi constructor
  Yoshi(int nbCrests);
  std::string WhatAmI() const;
  //New version of Accelerate
  void Accelerate();
};
