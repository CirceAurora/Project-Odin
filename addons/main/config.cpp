#include "script_component.hpp"

class CfgPatches {
    class ADDON_CLASS {
        name = ADDON_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {};
        author = "Circe Aurora";
        VERSION_CONFIG;
    };
};

#include "CfgFunctions.hpp"
#include "Odin.hpp"
