#include "script_component.hpp"
FIX_NAME
FIX_LINE_NUMBERS

if !(GET_CONFIG(zeus, "enabled")) exitWith {};

addMissionEventHandler ["PlayerConnected", {
    FIX_NAME

    params ["", "_uid", "_playerName", "", "_machineId"];

    if (GET_CONFIG_OR_DEFAULT(staff, _uid, -1) < STAFF_SENIOR) exitWith {};

    private _group = createGroup [sideLogic, true];
    _group setVariable ['isCuratorModuleGroup', true, true];

    private _zeus = _group createUnit ["ModuleCurator_F", [0, 0, 0], [], 0, "NONE"];

    _zeus setVariable ["owner", _uid, true];
    _zeus setVariable ["showNotification", false, true];
    _zeus setVariable ["Addons", 3, true];
    _zeus setVariable ["birdType", "", true];
    _zeus setVariable ["BIS_fnc_initModules_disableAutoActivation", false, true];
    _zeus addCuratorPoints 1;
    _zeus setCuratorCoef ["Place", 0];
    _zeus setCuratorCoef ["Delete", 0];

    removeAllCuratorAddons _zeus;
    _zeus addCuratorAddons COMPONENT_VARIABLE(addons);
    
    if (GET_CONFIG(zeus, "logging")) then {
        [_zeus, FUNCTION(zeusLogging)] remoteExec ["call", _machineId];
    };
    
    if (GET_CONFIG(zeus, "shareCreated")) then {
        [_zeus, FUNCTION(shareCreated)] remoteExec ["call", _machineId];
        _zeus addCuratorEditableObjects [COMPONENT_VARIABLE(placed), true];
    };

    [_zeus, {
        LOG_WARN("HI");
        _this addEventHandler ["CuratorObjectRegistered", {
            FIX_NAME

            private _restrictedModules = GET_CONFIG(zeus, "restrictedModules");
            
            _this select 1 apply {
                [GET_CONFIG_OR_DEFAULT(staff, getPlayerUID player, -1) >= _restrictedModules getOrDefault [_x, -1], 0, 0];
            }
        }];
    }] remoteExec ["call", _machineId];

    missionNamespace setVariable [QUOTE(JOIN2(MOD_TAG,zeus_)) + _uid, _zeus, false];
    COMPONENT_VARIABLE(modules) pushBack _zeus;

    LOG_DEBUG1("Created module for: %1", _playerName);
    ["You now have access to Zeus!", _machineId] call FUNCTION(message);
}];
