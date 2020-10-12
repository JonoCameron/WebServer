/*
 * Program to show that relay swiches work with Pi4b by counting 0-3 in
 * binary.
 * */
 
#include "RPI.h"

int map_peripheral(struct bcm2835_peripheral *p);

int main(){
	if(map_peripheral(&gpio) == -1)
  {
    printf("Failed to map the physical GPIO registers into the virtual memory space.\n");
    return -1;
  }
  
  INP_GPIO(4);
  OUT_GPIO(4);
  
  INP_GPIO(17);
  OUT_GPIO(17);
  
  printf("Start counting\n");
  
  while(1){
	 printf("0\n");
	 sleep(1);
	 GPIO_SET = 1 << 17;
	 printf("1\n");
	 sleep(1);
	 GPIO_CLR = 1 << 17;
	 GPIO_SET = 1 << 4;
	 printf("2\n");
	 sleep(1);
	 GPIO_SET = 1 << 17;
	 printf("3\n");
	 sleep(1);
	 GPIO_CLR = 1 << 4;
	 GPIO_CLR = 1 << 17;
 }
}
	 
  
