#include "typewise-alert.h"
#include "typewise-alert-config.h"
#include <stdio.h>

extern LimitCheck Limit[MAX_COOLING_TYPE];

BreachType classifyTemperatureBreach(CoolingType coolingType, 
                                     double temperatureInC)
{
    if(temperatureInC < Limit[coolingType].lowerLimit)
    {
        return TOO_LOW;
    }
    if(temperatureInC > Limit[coolingType].upperLimit)
    {
        return TOO_HIGH;
    }
    return NORMAL;
}

void checkAndAlert(AlertTarget alertTarget, BatteryCharacter batteryChar, 
                                            double temperatureInC)
{
    BreachType breachType = classifyTemperatureBreach(batteryChar.coolingType, 
                                                      temperatureInC);

    switch(alertTarget)
    {
        case TO_CONTROLLER:
            sendToController(breachType);
        break;
        case TO_EMAIL:
            sendToEmail(breachType);
        break;
    }
}

void sendToController(BreachType breachType)
{
    const unsigned short header = 0xfeed;
    printf("%x : %x\n", header, breachType);
}

void sendToEmail(BreachType breachType)
{
    const char* recepient = "a.b@c.com";
    const char* temp_cond[MAX_BREACH_TYPE] = {
                                      "Hi, the temperature is normal",
                                      "Hi, the temperature is too low\n",
                                      "Hi, the temperature is too high\n"
                                      };
    printf("To: %s\n", recepient);
    printf("%s \n", temp_cond[breachType]);
}
