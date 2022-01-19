#include "Character.h"

void test_speed(Character& c){
  std::cout<<"#################### Test of speed method ####################\n";
  std::cout<<"Speed : "<<c.speed()<<'\n';
}

void test_acceleration(Character& c){
  std::cout<<"#################### Test of Acceleration method ####################\n";
  int j=0;
  for(int i=0;i<=10;i++){
    std::cout<<j<<" acceleration -> speed should be of "<<i<<'\n';
    std::cout<<"Speed : "<<c.speed()<<'\n';
    c.Accelerate();
    j++;
  }
  std::cout<<j<<" acceleration -> speed should be of 10"<<'\n';
  std::cout<<"Speed : "<<c.speed()<<'\n';
}

void test_break(Character& c){
  std::cout<<"#################### Test of Break method ####################\n";
  int j=0;
  for(int i=0;i<=10;i++){
    std::cout<<j<<" break -> speed should be of "<<10-i<<'\n';
    std::cout<<"Speed : "<<c.speed()<<'\n';
    c.Break();
    j++;
  }
  std::cout<<j<<" break -> speed should be of 0"<<'\n';
  std::cout<<"Speed : "<<c.speed()<<'\n';
}

void test_Character(Character& c){
  test_speed(c);
  test_acceleration(c);
  test_break(c);
}

int main() {
  //We are going to create a Character and check it's
  //attributes and methods


  //!!!!!!Warning!!!!!!
  //Now it is abstract we can no longer create a character like that
  //This file has no longer use, it was only made to test our Character class
  //before it was abstract.
  //Character c;
  //test_Character(c);


  return 0;
}
