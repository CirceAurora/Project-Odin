#include "script_component.hpp"
FIX_NAME
FIX_LINE_NUMBERS

VARIABLE(messageQueue) = [];

[] spawn {
    waitUntil { getClientStateNumber == 10 };

    uiSleep 5;

    while { getClientStateNumber == 10 } do {

        while { count VARIABLE(messageQueue) > 0 } do {
            systemChat (VARIABLE(messageQueue) select 0);
            VARIABLE(messageQueue) deleteAt 0;
        };

        uiSleep 1;
    };
};
