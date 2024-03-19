#include "script_component.hpp"
FIX_NAME
FIX_LINE_NUMBERS

if !(GET_CONFIG(zeus, "enabled")) exitWith {};

private _updateList = GET_CONFIG(zeus, "updateList");

if (count _updateList == 0) exitWith {};

LOG_INFO("Editable objects list will now update every second");

_updateList spawn {
    while { true } do {
        {
            private _zeus = _x;

            {
                _zeus addCuratorEditableObjects [call _x, true]; 
            } forEach _this;
        } forEach allCurators;

        uiSleep 1;
    };
};
