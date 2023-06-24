#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"


/********    Temperature breach test for passive coolling type    **********/
TEST_CASE("Test1 : Temperature breach for passive coolling type low limit") {
    REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, -5) == TOO_LOW);
}

TEST_CASE("Test2 : Temperature breach for passive coolling type high limit") {
    REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, 40) == TOO_HIGH);
}

TEST_CASE("Test3 : Temperature breach for passive coolling type high limit") {
    REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, 30) == NORMAL);
}


/********   Temperature breach test for high active coolling type   **********/
TEST_CASE("Test4 : Temperature breach for high coolling type low limit") {
    REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING, -5) == TOO_LOW);
}

TEST_CASE("Test5 : Temperature breach for high coolling type high limit") {
    REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING, 50) == TOO_HIGH);
}

TEST_CASE("Test6 : Temperature breach for high coolling type high limit") {
    REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING, 40) == NORMAL);
}


/********   Temperature breach test for mid active coolling type   **********/
TEST_CASE("Test7 : Temperature breach for mid coolling type low limit") {
    REQUIRE(classifyTemperatureBreach(MED_ACTIVE_COOLING, -5) == TOO_LOW);
}

TEST_CASE("Test8 : Temperature breach for mid coolling type high limit") {
    REQUIRE(classifyTemperatureBreach(MED_ACTIVE_COOLING, 45) == TOO_HIGH);
}

TEST_CASE("Test9 : Temperature breach for mid coolling type high limit") {
    REQUIRE(classifyTemperatureBreach(MED_ACTIVE_COOLING, 35) == NORMAL);
}


TEST_CASE("Test10 : Check and alert for passive cooling and send to controller") {
    BatteryCharacter batteryChar = {PASSIVE_COOLING, "Dummy"};
    REQUIRE(classifyTemperatureBreach(batteryChar.coolingType,30) == NORMAL);
    checkAndAlert(TO_CONTROLLER, batteryChar, 30);
}

TEST_CASE("Test11 : Check and alert for passive cooling and send to email") {
    BatteryCharacter batteryChar = {PASSIVE_COOLING, "Dummy"};
    REQUIRE(classifyTemperatureBreach(batteryChar.coolingType,30) == NORMAL);
    checkAndAlert(TO_EMAIL, batteryChar, 30);
}
