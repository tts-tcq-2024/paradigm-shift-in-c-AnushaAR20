#ifndef BATTERY_H
#define BATTERY_H

// Define supported languages
#define ENGLISH 0
#define GERMAN 1

// Declare global variables
extern int current_language;
extern const char* messages[][3][3];

// Enum for parameter types
enum ParameterType {
    TEMPERATURE,
    SOC,
    CHARGE_RATE
};

// Function prototypes
void set_language(int language);
void print_message(int message_index, enum ParameterType parameter_type);
int is_value_out_of_range(float value, float min_value, float max_value);
int is_value_near_lower_limit(float value, float min_value, float tolerance);
int is_value_near_upper_limit(float value, float max_value, float tolerance);
int check_parameter(float value, float min_value, float max_value, float tolerance, enum ParameterType parameter_type);
int battery_is_ok(float temperature, float soc, float charge_rate);
void test_battery(float temperature, float soc, float charge_rate, int language);

#endif
