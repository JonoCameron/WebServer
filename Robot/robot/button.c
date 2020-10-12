/*
 * Working input/output test for RPI 4b GPIOs 
 * 
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
  
  
  
  printf("enter loop\n");
  while(1){
    INP_GPIO(4);
    OUT_GPIO(4);
    GPIO_SET = 1 << 4;
    if(GPIO_READ(17)){
      printf("1... 17 high, reading\n");
      }
    else{
      printf("2... 17 high, not reading\n");
      }
    sleep(1);
    
    GPIO_CLR = 1 << 4;
    if(GPIO_READ(17)){
      printf("3... 17 low, reading\n");
    }
    else{
      printf("4... 17 low, not reading\n");
    }
    
    sleep(1);
  }
}

