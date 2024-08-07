#include "Battery_Test.h"

void test_battery(float temperature, float soc, float charge_rate, int language) {
    set_language(language);
    if (battery_is_ok(temperature, soc, charge_rate)) {
        printf("Battery parameters are within acceptable range.\n");
    } else {
        printf("Battery parameters are out of range!\n");
    }
}
