#include "script_component.hpp"
FIX_NAME
FIX_LINE_NUMBERS

params ["_message", ["_client", [-2, 0] select hasInterface], "_jip1"];

private _jip = if (isNil "_jip1") then {
    _client == -2 || _client == 0
} else {
    _jip1;
};

private _id = _message remoteExec [QUOTE(FUNCTION(receiveMessage)), _client, _jip];

if !(_jip) exitWith {
    LOG_TRACE2("Sent message to: %1 - %2", _client, _message);
};

LOG_TRACE2("Added message to the JIP queue: %1 - %2", _id, _message);

[_id, _message] spawn {
    FIX_NAME

    params ["_id", "_message"];

    uiSleep 10;
    remoteExec ["", _id];

    LOG_TRACE2("Removed message from the JIP queue: %1 - %2", _id, _message);
};
