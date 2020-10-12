/* 
 * code from github "tasmanianfox" to connect hc sr04 us sensor
 * */

#include "RPI.h"

int map_peripheral(struct bcm2835_peripheral *p);

int main(){
	if(map_peripheral(&gpio) == -1)
  {
    printf("Failed to map the physical GPIO registers into the virtual memory space.\n");
    return -1;
  }

  INP_GPIO(17);
  GPIO_SET = 1 << 17;
  
  INP_GPIO(4);
  OUT_GPIO(4);
  
  GPIO_SET = 1 << 4;
  usleep(10);
  GPIO_CLR = 1 << 4;
  
  int echo, previousEcho, lowHigh, highLow;
  clock_t start_t, end_t;
  float rangeCm;
  long difference;
  lowHigh = highLow = echo = previousEcho = 0;
  while(0 == lowHigh || highLow == 0){
    previousEcho = echo;
    echo = GPIO_READ(17);
    if(0 == lowHigh && 0 == previousEcho && 1 == echo){
      lowHigh = 1;
      start_t = clock();
    }
    if(1 == lowHigh && 1 == previousEcho && 0 == echo){
      highLow = 1;
      end_t = clock();
    }
  }
  difference = ((double)(end_t - start_t))/CLOCKS_PER_SEC;
  rangeCm = difference * 34300 / 2;
  
  printf("start time %d\n", start_t);
  printf("end time %d \n", end_t);
  printf("Distance: %fcm.\n", rangeCm);
}

  
  
  
  
  
  
  
