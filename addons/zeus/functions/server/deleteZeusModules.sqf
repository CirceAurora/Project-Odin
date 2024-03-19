#include "script_component.hpp"
FIX_NAME
FIX_LINE_NUMBERS

if !(GET_CONFIG(zeus, "enabled")) exitWith {};

addMissionEventHandler ["HandleDisconnect", {
    FIX_NAME
    
	params ["", "_uid", "_playerName"];

    private _module = missionNamespace getVariable ( QUOTE(JOIN2(MOD_TAG,zeus_)) + _uid);

    if (isNil "_module" || {isNull _module}) exitWith {};

    private _modules = COMPONENT_VARIABLE(modules);
    _modules deleteAt (_modules find _zeus);

    deleteVehicle _module;
    missionNamespace setVariable [ QUOTE(JOIN2(MOD_TAG,zeus_)) + _uid, nil, false];
    
    LOG_INFO1("Deleted module for: %1", _playerName)
}];

if (GET_CONFIG(zeus, "deleteOtherModules")) then {
    {
        if (_x in COMPONENT_VARIABLE(modules)) exitWith {};
        
        deleteVehicle _x;
    } forEach allCurators;
};
