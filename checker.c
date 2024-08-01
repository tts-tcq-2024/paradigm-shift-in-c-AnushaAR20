#include <stdio.h>
#include <assert.h>
#include <string.h>

// Define supported languages
#define ENGLISH 0
#define GERMAN 1

int current_language = ENGLISH;

// Message dictionaries
const char* messages[][3][3] = {
    // English messages
    {
        {"Temperature is out of range", "Warning: Temperature - Approaching low temperature limit", "Warning: Temperature - Approaching high temperature limit"},
        {"State of Charge is out of range", "Warning: State of Charge - Approaching discharge", "Warning: State of Charge - Approaching charge peak"},
        {"Charge rate is out of range", "Warning: Charge rate - Approaching low charge rate", "Warning: Charge rate - Approaching high charge rate"}
    },
    // German messages
    {
        {"Temperatur ist außerhalb des Bereichs", "Warnung: Temperatur - Annäherung an untere Temperaturgrenze", "Warnung: Temperatur - Annäherung an obere Temperaturgrenze"},
        {"Ladezustand ist außerhalb des Bereichs", "Warnung: Ladezustand - Annäherung an Entladung", "Warnung: Ladezustand - Annäherung an Ladehöhepunkt"},
        {"Laderate ist außerhalb des Bereichs", "Warnung: Laderate - Annäherung an niedrige Laderate", "Warnung: Laderate - Annäherung an hohe Laderate"}
    }
};

enum ParameterType {
    TEMPERATURE,
    SOC,
    CHARGE_RATE
};

void print_message(int message_index, enum ParameterType parameter_type) {
    printf("%s\n", messages[current_language][parameter_type][message_index]);
}

int is_value_out_of_range(float value, float min_value, float max_value) {
    return (value < min_value || value > max_value);
}

int is_value_near_lower_limit(float value, float min_value, float tolerance) {
    return (value < min_value + tolerance);
}

int is_value_near_upper_limit(float value, float max_value, float tolerance) {
    return (value > max_value - tolerance);
}

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

int battery_is_ok(float temperature, float soc, float charge_rate) {
    float temperature_tolerance = 2.25; // 5% of upper limit 45
    float soc_tolerance = 4;            // 5% of upper limit 80
    float charge_rate_tolerance = 0.04; // 5% of upper limit 0.8
    
    return (check_parameter(temperature, 0, 45, temperature_tolerance, TEMPERATURE) &&
            check_parameter(soc, 20, 80, soc_tolerance, SOC) &&
            check_parameter(charge_rate, 0, 0.8, charge_rate_tolerance, CHARGE_RATE));
}

int main() 
{
    // Test in English
    current_language = ENGLISH;
    assert(battery_is_ok(25, 70, 0.7));
    assert(!battery_is_ok(50, 85, 0));
    assert(battery_is_ok(22, 76, 0.78)); // To test warning messages
    assert(battery_is_ok(3, 21, 0.05));  // To test warning messages
    
    // Test in German
    current_language = GERMAN;
    assert(battery_is_ok(25, 70, 0.7));
    assert(!battery_is_ok(50, 85, 0));
    assert(battery_is_ok(22, 76, 0.78)); // To test warning messages
    assert(battery_is_ok(3, 21, 0.05));  // To test warning messages
    
    return 0;
}
