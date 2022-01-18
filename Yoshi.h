#include "Character.h"
#include <stdlib.h>

class Yoshi : public Character{
protected:
  int _nbCrests;
public:
  Yoshi(int nbCrests);
  std::string WhatAmI() const;
  void Accelerate();
};
