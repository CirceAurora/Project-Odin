#include "script_component.hpp"
FIX_NAME
FIX_LINE_NUMBERS

_this addEventHandler ["CuratorGroupPlaced", {
    FIX_NAME

    params ["_curator", "_group"];

    LOG_INFO1("Sharing group - %1", _group);

    {
        _x addCuratorEditableObjects [_group, true];
    } forEach allCurators;
    COMPONENT_VARIABLE(placed) pushBack _group;
}];

_this addEventHandler ["CuratorMarkerPlaced", {
    FIX_NAME

    params ["_curator", "_marker"];

    LOG_INFO1("Sharing marker - %1", _marker);

    {
        _x addCuratorEditableObjects [_marker, true];
    } forEach allCurators;
    COMPONENT_VARIABLE(placed) pushBack _marker;
}];

_this addEventHandler ["CuratorObjectPlaced", {
    FIX_NAME

    params ["_curator", "_entity"];

    if (isNull _entity) exitWith {};

    LOG_INFO1("Sharing object - %1", _entity);

    {
        _x addCuratorEditableObjects [_entity, true];
    } forEach allCurators;
    COMPONENT_VARIABLE(placed) pushBack _entity;
}];
