#include "script_component.hpp"

class CfgPatches {
    class ADDON_CLASS {
        name = ADDON_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = { ADDON(Main) };
        author = "Circe Aurora";
        VERSION_CONFIG;
    };
};

#include "Odin.hpp"
