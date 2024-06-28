/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <assert.h>

int check(float min, float max, float val, char* parameter) 
{
  if (val < min || val > max) 
  {
    printf("%s is Out of range \n", parameter);
    return 0;
  }
  printf("%s is in range!\n", parameter);
  return 1;
}


int batteryIsOk(float temp, float soc, float charge) 
{
  return (check(0,45,temp, "Temperature") && check(20,80, soc, "State of charge") && check(0,0.8,charge, "Charge rate"));
}

int main() 
{
 assert(batteryIsOk(25, 70, 0.7));
 assert(!batteryIsOk(50, 85, 0));
 return 0;
}

