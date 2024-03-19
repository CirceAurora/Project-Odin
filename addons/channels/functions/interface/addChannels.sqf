#include "script_component.hpp"
FIX_NAME
FIX_LINE_NUMBERS

waitUntil { !isNil QUOTE(VARIABLE(channels)); };

private _channels = VARIABLE(channels) select {
    (getPlayerUID player) call (_x select 2);
} apply {
    _x params ["_name", "_radio", "_condition"];
    
    _radio radioChannelAdd [player];

    _name;
};

if (count _channels < 1) exitWith {};

LOG_INFO1("Joined channels: %1", _channels joinString ", ");

if (count _channels > 1) then {
    (format ["You have joined the channels '%1', and '%2'", _channels select [0, (count _channels) - 1] joinString "', '", _channels select -1]) call FUNCTION(receiveMessage);
} else {
    (format ["You have joined the channel '%1'", _channels select 0]) call FUNCTION(receiveMessage);
};
