#include "script_component.hpp"
FIX_LINE_NUMBERS

private _functions = _this;
private _toRun = [];
private _toRunLater = [];

{
    _x params ["_side", "_save"];

    if (_save) then {
        {
            missionNamespace setVariable [_x select 0, _x select 1, false];
            _toRun pushBack _x;
        } forEach (_functions select _side);
    };
} forEach [
    [SERVER,    isServer],
    [DEDICATED, isDedicated],
    [NONPLAYER, !hasInterface || isServer],
    [CLIENT,    !isDedicated],
    [INTERFACE, hasInterface],
    [HEADLESS,  !hasInterface && !isDedicated],
    [ALL,       true]
];

{
    switch (true) do {
        case (_x select 2 > 0): {
            _toRunLater pushBack _x;
            LOG_TRACE1("Running function later: %1", _x select 0);
        };
        case (_x select 2 < 0): {
            call (_x select 1);
            LOG_TRACE1("Ran function: %1", _x select 0);
        };
        default {
            LOG_TRACE1("Skipping function: %1", _x select 0);
        };
    }
} forEach ([_toRun, [], {
    _x select 2;
}] call BIS_fnc_sortBy);

_toRunLater spawn {
    FIX_NAME;

    waitUntil { getClientStateNumber == 10 };
    
    uiSleep 2.5;

    {
        call (_x select 1);
        LOG_TRACE1("Ran function: %1", _x select 0);
    } forEach _this;
};

LOG_DEBUG("Functions loaded");
