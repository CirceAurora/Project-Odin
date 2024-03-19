#include "script_component.hpp"
FIX_LINE_NUMBERS

private _functions = [[],[],[],[],[],[],[]];

{
    private _name = QUOTE(JOIN2(MOD_TAG,fnc_)) + configName _x;
    private _function = compileScript [getText (_x >> "file"), true];
    private _side = getNumber (_x >> "side");
    private _init = getNumber (_x >> "init");

    _functions select _side pushBack [_name, _function, _init];
} forEach ("true" configClasses (configFile >> QUOTE(MOD_CLASS) >> "Functions"));

_functions call FUNCTION(loadFunctions);

if (!isServer) exitWith {};

{
    _functions set [_x, []];
} forEach [SERVER, DEDICATED];

[_functions, FUNCTION(loadFunctions)] remoteExec ["call", -2, true];
