#include<stdio.h>
#include<stdint.h>
#include<limits.h>
int main()
{uint8_t sensor[100];
uint16_t adc[500];
int battery;
uint8_t battery1;
printf("sensor:%zu\n",sizeof(sensor));
printf("adc:%zu\n",sizeof(adc));
printf("battery:%zu\n",sizeof(battery));
printf("battery1:%zu\n",sizeof(battery1));
printf("uint8_t:%zu  and range:%u\n",sizeof(uint8_t),UINT8_MAX);
printf("uint16_t:%zu and range:%u \n",sizeof(uint16_t),UINT16_MAX);
printf("uint32_t:%zu  and range:%u \n",sizeof(uint32_t),UINT32_MAX);
return 0;}

