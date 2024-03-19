#include "\z\odin\addons\main\script_component.hpp"

// ["Name", ["Callsign", [R, G, B, A], { Condition }]]
// Name:         Name of the custom channel
// Callsign:     Callsign of the user - https://community.bistudio.com/wiki/radioChannelSetCallSign
// [R, G, B, A]: Color (RBGA) of the channel
// Condition:    Set to `true` to enable for all player, otherwise add SQF code
//
// Note: Max of 10 (including staff channel)
// Note: Order of `channels` matters
[
    ["channels", [
        "Staff"
    ]],
    ["Staff", ["Staff: %UNIT_NAME", [1, 0, 0, 1], { GET_CONFIG_OR_DEFAULT(staff, _this, -1) >= STAFF_VISITOR; }]]
];
