#include<stdio.h>
#include "Min_Max_Tolerance_Range_checker.h"
#include "Battery.h"

int is_value_out_of_range(float value, float min_value, float max_value) {
    return (value < min_value || value > max_value);
}

int is_value_near_lower_limit(float value, float min_value, float tolerance) {
    return (value < min_value + tolerance);
}

int is_value_near_upper_limit(float value, float max_value, float tolerance) {
    return (value > max_value - tolerance);
}
