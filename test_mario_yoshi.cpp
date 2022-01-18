#include "Mario.h"

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

void test_Mario(Character& c){
  test_speed(c);
  test_acceleration(c);
  test_break(c);
  std::cout<<"I am "<<c.WhatAmI()<<'\n';
}

int main() {
  //We are going to create a Mario and check it's
  //attributes and methods


  Mario m;
  test_Mario(m);


  return 0;
}
