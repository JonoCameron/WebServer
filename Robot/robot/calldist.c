#include "RPI.h"
#include "proxy.h"

//struct bcm2835_peripheral gpio = {GPIO_BASE};

int main(){
	
  
  double distance = Distance(17, 27);
  
  printf("Distance: %.2fcm.\n", distance);
  
  return 0;
}
  
