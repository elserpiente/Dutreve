#include <iostream>

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
};
