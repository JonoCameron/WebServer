/*
 * Program to test the echo coming back from an hc-sr04 ultrasonic 
 * module
 */
 
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
  double total_t;
  clock_t start_t, end_t;
  
  while(1){
    start_t = 0;
    end_t = 0;
    GPIO_SET = 1 << 4;
    usleep(10);
    GPIO_CLR = 1 << 4;
    int echo = GPIO_READ(17);
   
    while(echo == 0){
      start_t = clock();
      echo = GPIO_READ(17);
      //printf("looping\n");
    }
    
    echo = GPIO_READ(17);
    //printf("echo: %d\n", echo);
    
    while(echo == 131072){
      //printf("Receiving\n");
      end_t = clock();
      echo = GPIO_READ(17);
      }
    //printf("start time %d\n", start_t);
    //printf("end time %d \n", end_t);
    
    total_t = ((double)(end_t - start_t))/CLOCKS_PER_SEC;
    //printf("total time: %f\n", total_t);
    
    
    double distance = 34300*total_t/2;
    distance = sqrt(pow(distance, 2));
  
    usleep(100000);
    printf("Distance: %fcm.\n", distance);
    
    if(distance < 20){
      INP_GPIO(10);
      OUT_GPIO(10);
      GPIO_SET = 1 << 10;
    }
    else
      GPIO_CLR = 1 << 10;
  }
}
