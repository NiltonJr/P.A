/***************
* SensorController Class Implementation
*
* Sharang Phadke
* Sameer Chauhan
***************/

#ifndef SENSORCONTROLLER_CPP
#define SENSORCONTROLLER_CPP

#include "SensorController.h"


void SensorController::sample(){
  
  int i, j;
  float irSmoothNew[3] = {0.0};
  
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < N_IR-1; j++){
      irSignal[i][j] = irSignal[i][j+1];
      irSmoothNew[i] += ((float)(irSignal[i][j]))*(j+1)*2/(N_IR*(N_IR+1));
    }
  }
  
  irSignal[LEFT][N_IR-1] = analogRead(LEFT);
  irSignal[RIGHT][N_IR-1] = analogRead(RIGHT);
  irSignal[CENTER][N_IR-1] = analogRead(CENTER);
  
  irSmooth[LEFT] = irSmoothNew[LEFT];
  irSmooth[RIGHT] = irSmoothNew[RIGHT];
  irSmooth[CENTER] = irSmoothNew[CENTER];
}


#endif
