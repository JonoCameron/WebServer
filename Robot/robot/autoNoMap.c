#include "RPI.h"
#include "movement.h"
#include "proxy.h"

int main(){

  int forSensorTrig = 4,
      forSensorEcho = 17;
      /*
      backSensorTrig = 5,
      backSensorEcho = 6;
      rightSensor,
      leftSensor;
      */

  int forMotor = 13;
      /*
      backMotor = 19;
      */
      
  double forDist;
         /*
         backDist;
         rightDist,
         leftDist;
         */

  while(1){
    // call proximity functions. make distance() a macro

    forDist = Distance(4, 17);
    /*
    backDist  = Distance(backSensorTrig, backSensorEcho);
    rightDist = rightDistance(rightSensor);
    leftDist  = leftDistance(leftSensor);
    */
    // call movement functions

    //STOP();

    forOrBack(forDist, forMotor);
    //goBackward();
    //goLeft();
    //goRight();

  }
}
