#include "script_component.hpp"
FIX_NAME
FIX_LINE_NUMBERS

params ["_level", "_message"];

if (_level < GET_CONFIG_NO_WAIT(logging,"level",LEVEL_TRACE)) exitWith {};

diag_log formatText _message;

if (!isServer) then {
    [_level, _message] remoteExec [QUOTE(FUNCTION(log)), 2];
};
