#include "script_component.hpp"
FIX_NAME
FIX_LINE_NUMBERS

_this addEventHandler ["CuratorFeedbackMessage", {
    FIX_NAME
    params ["_curator", "_errorID"];
    LOG_INFO1("CuratorFeedbackMessage - %1", _errorID);
}];

_this addEventHandler ["CuratorGroupDoubleClicked", {
    FIX_NAME
    params ["_curator", "_group"];
    LOG_INFO1("CuratorGroupDoubleClicked - %1", _group);
}];

_this addEventHandler ["CuratorGroupPlaced", {
    FIX_NAME
    params ["_curator", "_group"];
    LOG_INFO1("CuratorGroupPlaced - %1", _group);
}];

_this addEventHandler ["CuratorGroupSelectionChanged", {
    FIX_NAME
    params ["_curator", "_group"];
    LOG_INFO1("CuratorGroupSelectionChanged - %1", _group);
}];

_this addEventHandler ["CuratorMarkerDeleted", {
    FIX_NAME
    params ["_curator", "_marker"];
    LOG_INFO1("CuratorMarkerDeleted - %1", _marker);
}];

_this addEventHandler ["CuratorMarkerDoubleClicked", {
    FIX_NAME
    params ["_curator", "_marker"];
    LOG_INFO1("CuratorMarkerDoubleClicked - %1", _marker);
}];

_this addEventHandler ["CuratorMarkerEdited", {
    FIX_NAME
    params ["_curator", "_marker"];
    LOG_INFO1("CuratorMarkerEdited - %1", _marker);
}];

_this addEventHandler ["CuratorMarkerPlaced", {
    FIX_NAME
    params ["_curator", "_marker"];
    LOG_INFO1("CuratorMarkerPlaced - %1", _marker);
}];

_this addEventHandler ["CuratorMarkerSelectionChanged", {
    FIX_NAME
    params ["_curator", "_marker"];
    LOG_INFO1("CuratorMarkerSelectionChanged - %1", _marker);
}];

_this addEventHandler ["CuratorObjectDeleted", {
    FIX_NAME
    params ["_curator", "_entity"];
    LOG_INFO2("CuratorObjectDeleted - %1 (%2)", _entity, typeOf _entity);
}];

_this addEventHandler ["CuratorObjectDoubleClicked", {
    FIX_NAME
    params ["_curator", "_entity"];
    LOG_INFO2("CuratorObjectDoubleClicked - %1 (%2)", _entity, typeOf _entity);
}];

_this addEventHandler ["CuratorObjectEdited", {
    FIX_NAME
    params ["_curator", "_entity"];
    LOG_INFO2("CuratorObjectEdited - %1 (%2)", _entity, typeOf _entity);
}];

_this addEventHandler ["CuratorObjectPlaced", {
    FIX_NAME
    params ["_curator", "_entity"];
    LOG_INFO2("CuratorObjectPlaced - %1 (%2)", _entity, typeOf _entity);
}];

_this addEventHandler ["CuratorObjectSelectionChanged", {
    FIX_NAME
    params ["_curator", "_entity"];
    LOG_INFO2("CuratorObjectSelectionChanged - %1 (%2)", _entity, typeOf _entity);
}];

_this addEventHandler ["CuratorPinged", {
    FIX_NAME
    params ["_curator", "_playerPing"];
    LOG_INFO1("CuratorPinged - %2", name _playerPing);
}];

_this addEventHandler ["CuratorWaypointDeleted", {
    FIX_NAME
    params ["_curator", "_waypoint"];
    LOG_INFO1("CuratorWaypointDeleted - %1", _waypoint);
}];

_this addEventHandler ["CuratorWaypointDoubleClicked", {
    FIX_NAME
    params ["_curator", "_waypoint"];
    LOG_INFO1("CuratorWaypointDoubleClicked - %1", _waypoint);
}];

_this addEventHandler ["CuratorWaypointEdited", {
    FIX_NAME
    params ["_curator", "_waypoint"];
    LOG_INFO1("CuratorWaypointEdited - %1", _waypoint);
}];

_this addEventHandler ["CuratorWaypointPlaced", {
    FIX_NAME
    params ["_curator", "_group", "_waypointID"];
    LOG_INFO2("CuratorWaypointPlaced - %1 (%2)", _group, _waypointID);
}];

_this addEventHandler ["CuratorWaypointSelectionChanged", {
    FIX_NAME
    params ["_curator", "_waypoint"];
    LOG_INFO1("CuratorWaypointSelectionChanged - %1", _waypoint);
}];
