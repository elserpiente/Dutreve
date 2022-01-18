#include "Mario.h"
#include "Yoshi.h"
#include <vector>
#include <unistd.h>

void test_speed(Character& c){
  std::cout<<"#################### Test of speed method ####################\n";
  std::cout<<"Speed : "<<c.speed()<<'\n';
}

void test_acceleration(Character& c){
  std::cout<<"#################### Test of Acceleration method ####################\n";
  int j=0;
  for(int i=0;i<=10;i++){
    if (i==1 || i==10){
      if(i*2<10){
        std::cout<<j<<" acceleration -> speed should be of "<<i<<" if I am Mario "<<i*2<<" if I am Yoshi"<<'\n';
      }else{
        std::cout<<j<<" acceleration -> speed should be of "<<i<<" if I am Mario "<<10<<" if I am Yoshi"<<'\n';
      }
      std::cout<<"Speed : "<<c.speed()<<'\n';
    }
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
    if (i==1 || i==10){
      std::cout<<j<<" break -> speed should be of "<<10-i<<'\n';
      std::cout<<"Speed : "<<c.speed()<<'\n';
    }
    c.Break();
    j++;
  }
  std::cout<<j<<" break -> speed should be of 0"<<'\n';
  std::cout<<"Speed : "<<c.speed()<<'\n';
}

void test_Mario_Yoshi(Character& c){
  std::cout<<"I am "<<c.WhatAmI()<<'\n';
  test_speed(c);
  test_acceleration(c);
  test_break(c);
}

void race(std::vector <Character*>& runners){
  std::cout<<"#################### Race !!! ####################\n";
  if (runners.size()==2){
    std::cout<<"Runner 1 : "<<runners[0]->WhatAmI()<<"|.\n";
    std::cout<<"Runner 2 : "<<runners[1]->WhatAmI()<<"|,\n";

    int first=0;
    std::vector <int> meters;
    for(std::vector<Character*>::iterator it = runners.begin(); it != runners.end(); it++){
      meters.push_back(100);
      for (int i=0;i<=10;i++){
        (*it)->Break();
      }
    }
    std::string position(100,' ');
    position=';'+position;
    std::string piste(98,'#');
    piste=piste+"II";
    std::cout<<piste<<'\n';
    char pawn1,pawn2;
    while(first!=100){
      for(int i=0;i<runners.size();i++){
        position[100-meters[i]]=' ';
        meters[i]=meters[i]-runners[i]->speed();
        if (meters[i]>100){
          meters[i]=100;
        }
        if(100-meters[i]>first){
          first=100-meters[i];
        }
        runners[i]->Accelerate();
      }
      if (meters[0]==meters[1]){
        position[100-meters[0]]=';';
      } else{
        position[100-meters[0]]='.';
        position[100-meters[1]]=',';
        }
      std::cout<<position<<'\r';
      sleep(1);//sleeps for 3 second

    }

    if (meters[0]==meters[1]){
      std::cout<<runners[0]->WhatAmI()<<" and "<<runners[1]->WhatAmI()<<" are ex aequo";
    } else{
      if (meters[0]<meters[1]){
        std::cout<<runners[0]->WhatAmI()<<" is the winner ! "<<runners[1]->WhatAmI()<<" loses.";
      } else{
        std::cout<<runners[1]->WhatAmI()<<" is the winner ! "<<runners[0]->WhatAmI()<<" loses.";
        }
      }
    } else{
      std::cout<<"Error, our races only allows 2 runners but you have "<<runners.size()<<" !\n";
      std::cout<<"Remove or add some runners and try again."<<'\n';
    }
}

int main() {
  //We are going to create a Mario and check it's
  //attributes and methods


  Mario m;
  Yoshi y;
  test_Mario_Yoshi(m);
  test_Mario_Yoshi(y);

  std::vector <Character*> runners;
  runners.push_back(new Mario());
  runners.push_back(new Yoshi());

  race(runners);






  return 0;
}
