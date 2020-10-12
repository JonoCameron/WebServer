#ifndef MOVEMENT_H_
#define MOVEMENT_H_

/*void STOP(int forMotor,
          int backMotor,
          int leftTurn,
          int rightTurn); // stop all movement to avoid overwriting control
                          // motors.*/
void forOrBack(double forDist, int forMotor); // read rear distance,
                                               // move forwards.
/*void goBackward(double forDist, int backMotor);// read front distance, move
                                               //backwards
void leftOrRight(double rightDist, double leftDist, int leftTurn, int rightTurn);   // read space to right, turn left
/*void goRight(double leftDist, int rightTurn);  // read space to left, turn right*/


#endif // MOVEMENT_H
