#include "car.h"
#include <stdio.h>
#include <iostream>
#include "string.h"
#include "utilities.h"

using namespace std;

Car::Car(int x, int y){
  position_x[1] = x-4;
  position_x[0] = position_x[1]-1;
  position_x[2] = position_x[1]+1;

  position_y[1] = y/2;
  position_y[0] = position_y[1]-1;
  position_y[2] = position_y[1]+1;

  bound_y = y-1;
  fuel = 1000;
  life= 1000;
}

void Car::move(){
  char move = get_input();

  if(move == 'a' && position_y[0] > 0){
    for(int i=0; i<sizeof(position_y)/sizeof(position_y[0]); i++){
        position_y[i]--;
      }
  } else if (move == 'd' && position_y[2] < bound_y){
    for(int i=0; i<sizeof(position_y)/sizeof(position_y[0]); i++){
      position_y[i]++;
    }
  }
}

void Car::print(){
  for(int i=0; i<sizeof(position_x)/sizeof(position_x[0]); i++){
    cout << string("\033[") + to_string(position_x[i]) + ";" + to_string(position_y[0]+2) + "H";
    for(int j=0; j<sizeof(position_y)/sizeof(position_y[0]); j++){
        cout << '*';
      }
  }
}
