#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"

#define PASSIVE_COOLING_TYPE    0
#define HI_ACTIVE_COOLING_TYPE  1
#define MED_ACTIVE_COOLING_TYPE 2

/********    Temperature breach test for passive coolling type    **********/
TEST_CASE("Test1 : Temperature breach for passive coolling type low limit") {
  REQUIRE(inferBreach(PASSIVE_COOLING_TYPE, -5) == TOO_LOW);
}

TEST_CASE("Test2 : Temperature breach for passive coolling type high limit") {
  REQUIRE(inferBreach(PASSIVE_COOLING_TYPE, 40) == TOO_HIGH);
}

TEST_CASE("Test3 : Temperature breach for passive coolling type high limit") {
  REQUIRE(inferBreach(PASSIVE_COOLING_TYPE, 30) == NORMAL);
}


/********   Temperature breach test for high active coolling type   **********/
TEST_CASE("Test4 : Temperature breach for high coolling type low limit") {
  REQUIRE(inferBreach(HI_ACTIVE_COOLING_TYPE, -5) == TOO_LOW);
}

TEST_CASE("Test5 : Temperature breach for high coolling type high limit") {
  REQUIRE(inferBreach(HI_ACTIVE_COOLING_TYPE, 50) == TOO_HIGH);
}

TEST_CASE("Test6 : Temperature breach for high coolling type high limit") {
  REQUIRE(inferBreach(HI_ACTIVE_COOLING_TYPE, 40) == NORMAL);
}


/********   Temperature breach test for mid active coolling type   **********/
TEST_CASE("Test7 : Temperature breach for mid coolling type low limit") {
  REQUIRE(inferBreach(MED_ACTIVE_COOLING_TYPE, -5) == TOO_LOW);
}

TEST_CASE("Test8 : Temperature breach for mid coolling type high limit") {
  REQUIRE(inferBreach(MED_ACTIVE_COOLING_TYPE, 45) == TOO_HIGH);
}

TEST_CASE("Test9 : Temperature breach for mid coolling type high limit") {
  REQUIRE(inferBreach(MED_ACTIVE_COOLING_TYPE, 35) == NORMAL);
}
