#include "script_component.hpp"
FIX_NAME
FIX_LINE_NUMBERS

VARIABLE(channels) = GET_CONFIG(channels, "channels") apply {
    LOG_TRACE1("Created channel: %1", _x);
    
    GET_CONFIG(channels, _x) params ["_callsign", "_color", "_condition"];
    [_x, radioChannelCreate [_color, _x, _callsign, []], _condition];
};

publicVariable QUOTE(VARIABLE(channels));

LOG_DEBUG("Created channels");
