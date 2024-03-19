#include "script_component.hpp"
FIX_NAME
FIX_LINE_NUMBERS

LOG_TRACE("Loading config...");

VARIABLE(config) = createHashMapFromArray (("true" configClasses (configFile >> QUOTE(MOD_CLASS) >> "Config")) apply {
    private _config = createHashMapFromArray (call compileScript [getText (_x >> "file"), true]);
    private _file = format ["@ODIN\%1.sqf", configName _x];
    
    if (fileExists _file) then {
        _config merge [createHashMapFromArray (call compileScript [_file, true]), true];
    } else {
        _config;
    };

    LOG_TRACE2("Loaded config: '%1' -> %2", configName _x, _config);

    [configName _x, _config];
});

LOG_DEBUG("Loaded config");
LOG_INFO("Further logging shall respect log level set in the config");

publicVariable QUOTE(VARIABLE(config));
