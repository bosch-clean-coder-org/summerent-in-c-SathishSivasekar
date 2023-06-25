#pragma once

#define  MAX_BREACH_TYPE         3u
#define  MAX_COOLING_TYPE        3u
#define  PASSIVE_COOLING_LL      0u
#define  PASSIVE_COOLING_UL      35u
#define  HI_ACTIVE_COOLING_LL    0u
#define  HI_ACTIVE_COOLING_UL    45u
#define  MED_ACTIVE_COOLING_LL   0u
#define  MED_ACTIVE_COOLING_UL   40u

typedef enum {
  PASSIVE_COOLING,
  HI_ACTIVE_COOLING,
  MED_ACTIVE_COOLING
} CoolingType;

typedef enum {
  NORMAL,
  TOO_LOW,
  TOO_HIGH
} BreachType;

BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC);

typedef enum {
  TO_CONTROLLER,
  TO_EMAIL
} AlertTarget;

typedef struct {
  CoolingType coolingType;
  char brand[48];
} BatteryCharacter;

void checkAndAlert(
  AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC);

void sendToController(BreachType breachType);
void sendToEmail(BreachType breachType);
