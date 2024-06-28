#include <stdio.h>
#include <assert.h>

typedef struct {
  float min;
  float max;
  float value;
  const char* parameter;
} Parameter;

int isInRange(Parameter param) 
{
  if (param.value >= param.min && param.value <= param.max) 
  {
    printf("%s is in range!\n", param.parameter);
    return 1;
  } 
  else 
  {
    printf("%s is Out of range!\n", param.parameter);
    return 0;
  }
}

int batteryIsOk(float temp, float soc, float charge) 
{
  Parameter params[] = {
    {0, 45, temp, "Temperature"},
    {20, 80, soc, "State of charge"},
    {0, 0.8, charge, "Charge rate"}
  };
  
  for (int i = 0; i < 3; i++) {
    if (!isInRange(params[i])) {
      return 0;
    }
  }
  return 1;
}

int main() 
{
   assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
  return 0;
}
