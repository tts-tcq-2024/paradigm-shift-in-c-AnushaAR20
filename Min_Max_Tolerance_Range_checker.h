#ifndef MIN_MAX_TOLERANCE_RANGE_CHECKER_H_
#define MIN_MAX_TOLERANCE_RANGE_CHECKER_H_

#include "Battery.h"

int is_value_out_of_range(float value, float min_value, float max_value);
int is_value_near_lower_limit(float value, float min_value, float tolerance);
int is_value_near_upper_limit(float value, float max_value, float tolerance);
#endif
