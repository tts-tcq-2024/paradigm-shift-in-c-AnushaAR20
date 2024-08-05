#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "Battery.h"

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
