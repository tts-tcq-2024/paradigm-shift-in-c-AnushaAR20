#ifndef CHECK_PARAMETER_H
#define CHECK_PARAMETER_H

#include "Battery.h"

int check_parameter(float value, float min_value, float max_value, float tolerance, enum ParameterType parameter_type);

#endif // CHECK_PARAMETER_H
