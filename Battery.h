#ifndef BATTERY_H
#define BATTERY_H

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

#endif
