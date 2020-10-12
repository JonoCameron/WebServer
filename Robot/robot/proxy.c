#include "RPI.h"
#include "proxy.h"

int map_peripheral(struct bcm2835_peripheral *p);

double Distance(int Trigger, int Echo){
  
  if(map_peripheral(&gpio) == -1){
		printf("Failed to map the physical GPIO registers into the virtual memory space.\n");
		return -1;
	}
  
  INP_GPIO(Echo);
  GPIO_SET = 1 << Echo;

  INP_GPIO(Trigger);
  OUT_GPIO(Trigger);
  double total_t;
  clock_t start_t, end_t;


  start_t = 0;
  end_t = 0;
  GPIO_SET = 1 << Trigger;
  usleep(10);
  GPIO_CLR = 1 << Trigger;
  int echo = GPIO_READ(Echo);

  while(echo == 0){
    start_t = clock();
    echo = GPIO_READ(Echo);
  }

  echo = GPIO_READ(Echo);

  while(echo == 131072){
    end_t = clock();
    echo = GPIO_READ(Echo);
  }

  total_t = ((double)(end_t - start_t)) / CLOCKS_PER_SEC;

  double distance = 34300 * total_t / 2;
  distance = sqrt(pow(distance, 2));

  //printf("Distance: %.2fcm.\n", distance);
  return distance;
}


/*
double backwardDist(int backSensorTrig, int backSensorEcho){
  INP_GPIO(backSensorEcho);
  GPIO_SET = 1 << backSensorEcho;

  INP_GPIO(backSensorTrig);
  OUT_GPIO(backSensorTrig);
  double total_t;
  clock_t start_t, end_t;


  start_t = 0;
  end_t = 0;
  GPIO_SET = 1 << backSensorTrig;
  usleep(10);
  GPIO_CLR = 1 << backSensorTrig;
  int echo = GPIO_READ(backSensorEcho);

  while(echo == 0){
    start_t = clock();
    echo = GPIO_READ(backSensorEcho);
  }

  echo = GPIO_READ(backSensorEcho);

  while(echo == 131072){
    end_t = clock();
    echo = GPIO_READ(backSensorEcho);
  }

  total_t = ((double)(end_t - start_t)) / CLOCKS_PER_SEC;

  double distance = 34300 * total_t / 2;
  distance = sqrt(pow(distance, 2));

  printf("Distance: %.2fcm.\n", distance);
  return distance;

}
*/
