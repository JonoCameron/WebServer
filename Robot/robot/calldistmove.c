#include "RPI.h"
#include "proxy.h"
#include "movement.h"

int main(){
	
	int trig = 4,
		echo = 17,
		motor = 10;
	double distance = Distance(trig, echo);
	
	printf("Distance: %.2fcm.\n", distance);
  
	forOrBack(distance, motor);
  
	return 0;
}

