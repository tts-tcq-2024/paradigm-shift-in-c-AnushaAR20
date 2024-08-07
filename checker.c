#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "Check_Battery_Parameters.h"
#include "Check_battery_IsOK.h"
#include "Print_message.h"
#include "Min_Max_Tolerance_Range_checker.h"

void test_battery(float temperature, float soc, float charge_rate, int language) {
    set_language(language);
    if (battery_is_ok(temperature, soc, charge_rate)) {
        printf("Battery parameters are within acceptable range.\n");
    } else {
        printf("Battery parameters are out of range!\n");
    }
}

int main() 
{
    // Test cases
    printf("Testing in English:\n");
    test_battery(25, 70, 0.7, ENGLISH);
    test_battery(50, 85, 0, ENGLISH);
    test_battery(22, 76, 0.78, ENGLISH);
    test_battery(3, 21, 0.05, ENGLISH);
    
    printf("\nTesting in German:\n");
    test_battery(25, 70, 0.7, GERMAN);
    test_battery(50, 85, 0, GERMAN);
    test_battery(22, 76, 0.78, GERMAN);
    test_battery(3, 21, 0.05, GERMAN);
    
    return 0;
}
