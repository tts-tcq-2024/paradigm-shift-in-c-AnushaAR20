#include<stdio.h>

int check_parameter(float value, float min_value, float max_value, float tolerance, enum ParameterType parameter_type) {
    if (is_value_out_of_range(value, min_value, max_value)) {
        print_message(0, parameter_type);
        return 0;
    }
    if (is_value_near_lower_limit(value, min_value, tolerance)) {
        print_message(1, parameter_type);
    }
    if (is_value_near_upper_limit(value, max_value, tolerance)) {
        print_message(2, parameter_type);
    }
    return 1;
}
