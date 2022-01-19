#include "Mario.h"
#include "Yoshi.h"
#include <vector>
#include <unistd.h>

void test_speed(Character& c){
  //Print the speed of the Character passed in parameters
  std::cout<<"#################### Test of speed method ####################\n";
  std::cout<<"Speed : "<<c.speed()<<'\n';
}

void test_acceleration(Character& c){
  //Print at which acceleration we are, the theoretical speed according to the Character
  //Then print the speed of the Character passed in parameters
  //Accelerate the Character passed in parameters
  //Repeat the three last operations 10 times
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

  //Check if the max_speed isn't outpassed
  std::cout<<j<<" acceleration -> speed should be of 10"<<'\n';
  std::cout<<"Speed : "<<c.speed()<<'\n';
}

void test_break(Character& c){
  //Do the same thing as test_acceleration but instead of accelarating
  //the character it makes it break
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
  //Print which character is passed in parameters and test its Speed
  //its acceleration and its break.
  std::cout<<"I am "<<c.WhatAmI()<<'\n';
  test_speed(c);
  test_acceleration(c);
  test_break(c);
}

void race(std::vector <Character*>& runners){
  //Start a graphic race between two characters in the terminal
  std::cout<<"#################### Race !!! ####################\n";
  if (runners.size()==2){
    //Show who's who
    std::cout<<"Runner 1 : "<<runners[0]->WhatAmI()<<"|.\n";
    std::cout<<"Runner 2 : "<<runners[1]->WhatAmI()<<"|,\n";

    //The first character in the race is at the 0 position
    int first=0;
    std::vector <int> meters;
    //We initialize the remaining number of meters to run for each characters
    //and reset their starting speed to 0
    for(std::vector<Character*>::iterator it = runners.begin(); it != runners.end(); it++){
      meters.push_back(100);
      for (int i=0;i<=10;i++){
        (*it)->Break();
      }
    }
    //We create the graphic strings that will be displayed on the terminal
    std::string position(100,' ');
    position=';'+position;
    std::string piste(98,'#');
    piste=piste+"II";
    std::cout<<piste<<'\n';
    //We start our race
    while(first!=100){
      //We make our characters move
      for(int i=0;i<runners.size();i++){
        position[100-meters[i]]=' ';
        meters[i]=meters[i]-runners[i]->speed();
        if (meters[i]>100){
          meters[i]=100;
        }
        //We set who is first after this move
        if(100-meters[i]>first){
          first=100-meters[i];
        }
        //We make our characters accelerate
        runners[i]->Accelerate();
      }
      //We put our characters to their new position in the string
      if (meters[0]==meters[1]){
        position[100-meters[0]]=';';
      } else{
        position[100-meters[0]]='.';
        position[100-meters[1]]=',';
        }
      //We display the actual race state and wait one second to allows
      //us poor humans to see them
      std::cout<<position<<'\r';
      sleep(1);

    }
    //We print the result of the race
    if (meters[0]==meters[1]){
      std::cout<<runners[0]->WhatAmI()<<" and "<<runners[1]->WhatAmI()<<" are ex aequo\n";
    } else{
      if (meters[0]<meters[1]){
        std::cout<<runners[0]->WhatAmI()<<" is the winner ! "<<runners[1]->WhatAmI()<<" loses.\n";
      } else{
        std::cout<<runners[1]->WhatAmI()<<" is the winner ! "<<runners[0]->WhatAmI()<<" loses.\n";
        }
      }
    } else{
      //Our race has been programmed for two runners so if it's not the case
      //of the vector passed in parameters we send this message
      std::cout<<"Error, our races only allows 2 runners but you have "<<runners.size()<<" !\n";
      std::cout<<"Remove or add some runners and try again."<<'\n';
    }
}

int main() {
  //We are going to create a Mario and check it's
  //attributes and methods

//We create a Mario and a 3 crested Yoshi
  Mario m;
  Yoshi y(3);
  //We check if they follow what we specify in the declarations
  test_Mario_Yoshi(m);
  test_Mario_Yoshi(y);

  //We create a vector of runners and add a Mario and a 4 crested Yoshi in it
  std::vector <Character*> runners;
  runners.push_back(new Mario());
  runners.push_back(new Yoshi(4));

  //We check if the runners accelerate at a good speed according of their type
  race(runners);

  //We delete our two characters to avoid any memory leak using an iterator for loop
  for(std::vector<Character*>::iterator it = runners.begin(); it != runners.end(); it++){
    delete(*(it));
  }
  //We recreate two characters for fun
  runners[0]=new Yoshi(3);
  runners[1]=new Yoshi(4);
  //runners.push_back(new Yoshi(5));
  //We check if the runners accelerate at a good speed according of their type
  race(runners);

//We delete our two characters to avoid any memory leak using a range based for loop
  for(int i=0;i<runners.size();i++){
    delete(runners[i]);
  }


  return 0;
}
