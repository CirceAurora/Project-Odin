#include "script_component.hpp"
FIX_NAME
FIX_LINE_NUMBERS

if !(GET_CONFIG(zeus, "enabled")) exitWith {};

LOG_INFO("Zeus addon enabled");
    
private _cfgPatches = configfile >> "CfgPatches";

COMPONENT_VARIABLE(addons) = [];
COMPONENT_VARIABLE(modules) = [];
COMPONENT_VARIABLE(placed) = [];

publicVariable QUOTE(COMPONENT_VARIABLE(placed));

for "_i" from 0 to (count _cfgPatches - 1) do {
	_configName = configName (_cfgPatches select _i);
	COMPONENT_VARIABLE(addons) pushBack _configName;
    
    LOG_TRACE1("Found addon: %1", _configName);
};

COMPONENT_VARIABLE(addons) call BIS_fnc_activateAddons;

LOG_DEBUG("Zeus loaded");
