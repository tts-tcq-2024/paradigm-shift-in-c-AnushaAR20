#include<stdio.h>
#include "Battery.h"
#include "Check_Battery_Parameters.h"

static int check_out_of_range(float value, float min_value, float max_value, enum ParameterType parameter_type) {
    if (is_value_out_of_range(value, min_value, max_value)) {
        print_message(0, parameter_type);
        return 1;
    }
    return 0;
}

static void check_near_lower_limit(float value, float min_value, float tolerance, enum ParameterType parameter_type) {
    if (is_value_near_lower_limit(value, min_value, tolerance)) {
        print_message(1, parameter_type);
    }
}

static void check_near_upper_limit(float value, float max_value, float tolerance, enum ParameterType parameter_type) {
    if (is_value_near_upper_limit(value, max_value, tolerance)) {
        print_message(2, parameter_type);
    }
}

int check_parameter(float value, float min_value, float max_value, float tolerance, enum ParameterType parameter_type) {
    if (check_out_of_range(value, min_value, max_value, parameter_type)) {
        return 0;
    }
    check_near_lower_limit(value, min_value, tolerance, parameter_type);
    check_near_upper_limit(value, max_value, tolerance, parameter_type);
    return 1;
}
