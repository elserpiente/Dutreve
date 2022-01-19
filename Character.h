#ifndef DEF_CHARACTER
#define DEF_CHARACTER

#include <iostream>
#include <string>

class Character{
protected:
  float _speed;
  float _max_speed;
public:
  Character();
  ~Character()=default;
  //virtual function to force the use of derived class's version instead of this one
  //as it's not pure if no derived class's version has been declared this one will be used
  virtual void Accelerate();
  void Break();
  inline float speed() const{
    return _speed;
  }
  virtual std::string WhatAmI() const = 0;
  /*
  This line above declare a pure virtual function, when the compiler sees a function
  inherited of this function it make a call to the corresponding function according
  to the type of object pointed by a pointer rather than the type of the object declared
  in the pointer. Finally the fact it's pure makes this class abstract and forces the
  declaration of a version of this function in the class that inherit this one.
  It's mainly use when each derived class will need a declaration of this function
  but it makes no sense to give the function of the base class a declaration.
  */
};

#endif
