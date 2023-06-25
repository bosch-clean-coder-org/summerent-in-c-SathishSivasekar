#include"typewise-alert-config.h"
#include"typewise-alert.h"

LimitCheck Limit[MAX_COOLING_TYPE] = {
    {
        PASSIVE_COOLING_LL,
        PASSIVE_COOLING_UL,
    },
    {
        HI_ACTIVE_COOLING_LL,
        HI_ACTIVE_COOLING_UL,
    },
    {
        MED_ACTIVE_COOLING_LL,
        MED_ACTIVE_COOLING_UL
    },
};
