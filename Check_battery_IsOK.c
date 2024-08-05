#include<stdio.h>

int battery_is_ok(float temperature, float soc, float charge_rate) 
{
    float temperature_tolerance = 2.25; // 5% of upper limit 45
    float soc_tolerance = 4;            // 5% of upper limit 80
    float charge_rate_tolerance = 0.04; // 5% of upper limit 0.8
    
    return (check_parameter(temperature, 0, 45, temperature_tolerance, TEMPERATURE) &&
            check_parameter(soc, 20, 80, soc_tolerance, SOC) &&
            check_parameter(charge_rate, 0, 0.8, charge_rate_tolerance, CHARGE_RATE));

}
