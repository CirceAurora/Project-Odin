#include "script_component.hpp"
FIX_NAME
FIX_LINE_NUMBERS

if !(GET_CONFIG(skills, "enabled")) exitWith {};

LOG_INFO("Skills addon enabled");

addMissionEventHandler ["EntityCreated", {
    FIX_NAME
    
    params ["_entity"];

    if (isPlayer _entity) exitWith {};

    {
        _x params ["_skill", "_multiplier"];

        _entity setSkill [_skill, (_entity skill _skill) / _multiplier];
    } forEach (GET_CONFIG(skills, side _entity));
}];
