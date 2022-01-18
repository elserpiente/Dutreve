#include "Character.h"

class Yoshi : public Character{
public:
  std::string WhatAmI() const;
  void Accelerate();
};
