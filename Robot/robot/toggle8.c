#include "RPI.h"

int map_peripheral(struct bcm2835_peripheral *p);


int main()
{
  if(map_peripheral(&gpio) == -1)
  {
    printf("Failed to map the physical GPIO registers into the virtual memory space.\n");
    return -1;
  }

  // Define pin 7 as output
  INP_GPIO(14);
  OUT_GPIO(14);

  while(1)
  {
    // Toggle pin 7 (blink a led!)
    GPIO_SET = 1 << 14;
    printf("On\n");
    sleep(1);

    GPIO_CLR = 1 << 14;
    printf("Off\n");
    sleep(1);
  }

  return 0;
}
