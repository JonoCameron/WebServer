#include "RPI.h"
#include "movement.h"

int map_peripheral(struct bcm2835_peripheral *p);
/*
void STOP(int forMotor,
          int backMotor,
          int leftTurn,
          int rightTurn){
  GPIO_CLR = 1 << forMotor;
  GPIO_CLR = 1 << backMotor;
  GPIO_CLR = 1 << leftTurn;
  GPIO_CLR = 1 << rightTurn;
}*/
void forOrBack(double forDist, int forMotor){
  /*
  if (backDist < 20){
    INP_GPIO(forMotor);
    OUT_GPIO(forMotor);
    GPIO_CLR = 1 << backMotor;
    GPIO_SET = 1 << forMotor;
    printf("Going forwards\n");
  }
  else */
  if (forDist < 20){
    INP_GPIO(forMotor);
    OUT_GPIO(forMotor);
    GPIO_CLR = 1 << forMotor;
    //GPIO_SET = 1 << backMotor;
    printf("Going backwards\n");
  }
  else
    printf("Continue on route.\n");
}
/*
void goBackward(double forDist, int backMotor){
  if (forDist < 20){
    INP_GPIO(backMotor);
    OUT_GPIO(backMotor);
    GPIO_SET = 1 << backMotor;
  }
  else{
    printf("\nFront clear\n");
  }
}

void goLeft(double rightDist, int leftTurn){
  if (rightDist < 20){
    INP_GPIO(leftTurn);
    OUT_GPIO(leftTurn);
    GPIO_SET = 1 << leftTurn;
  }
  else{
    printf("\nRight clear\n");
  }
}

void goRight(double leftDist, int rightTurn){
  if (leftDist < 20){
    INP_GPIO(rightTurn);
    OUT_GPIO(rightTurn);
    GPIO_SET = 1 << rightTurn;
  }
  else{
    printf("\nLeft clear\n");
  }
}
*/
