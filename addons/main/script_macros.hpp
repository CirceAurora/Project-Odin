// Common
#define _QUOTE(MESSAGE)                             #MESSAGE
#define QUOTE(MESSAGE)                              _QUOTE(MESSAGE)
#define _JOIN2(COMPONENT0,COMPONENT1)               COMPONENT0##_##COMPONENT1
#define JOIN2(COMPONENT0,COMPONENT1)                _JOIN2(COMPONENT0,COMPONENT1)
#define _JOIN3(COMPONENT0,COMPONENT1,COMPONENT2)    COMPONENT0##_##COMPONENT1##_##COMPONENT2
#define JOIN3(COMPONENT0,COMPONENT1,COMPONENT2)     _JOIN3(COMPONENT0,COMPONENT1,COMPONENT2)
#define _FIX_LINE_NUMBERS(SHARP)                    SHARP##line __LINE__ __FILE__
#define FIX_LINE_NUMBERS                            _FIX_LINE_NUMBERS(#)
#define FIX_NAME                                    private _fnc_scriptNameMain = (QUOTE(JOIN2(MOD_TAG,fnc_)) + (__FILE__ regexFind ["([a-zA-Z]+)\.sqf"] select 0 select 1 select 0)); \
                                                    private _fnc_scriptNameParent = if (isNil '_fnc_scriptName') then {_fnc_scriptNameMain} else {_fnc_scriptName}; \
                                                    private _fnc_scriptName = _fnc_scriptNameMain; \
                                                    scriptName _fnc_scriptName;

// config.cpp
#define ADDON_CLASS         MOD_CLASS##COMPONENT_CLASS
#define ADDON(COMPONENT)    QUOTE(MOD_CLASS##COMPONENT)
#define ADDON_NAME          QUOTE(MOD_NAME - COMPONENT_CLASS)
#define VERSION             MAJOR.MINOR
#define VERSION_STR         QUOTE(VERSION_TYPE MAJOR.MINOR.PATCH)
#define VERSION_AR          MAJOR,MINOR,PATCH
#define VERSION_CONFIG      version = VERSION; versionStr = VERSION_STR; versionAr[] = { VERSION_AR }

// CfgFunctions.hpp, Odin.hpp
#define _FUNCTION(FUNCTION)                 QUOTE(\PREFIX\MOD\addons\COMPONENT\functions\FUNCTION.sqf)
#define CFG_FUNCTION(FUNCTION)              class FUNCTION { file = _FUNCTION(FUNCTION); }
#define CFG_FUNCTION_PRE_INIT(FUNCTION)     class FUNCTION { file = _FUNCTION(FUNCTION); preInit = 1;  }

#define ODIN_FUNCTION_SERVER(FUNCTION,INIT)     class FUNCTION { file = _FUNCTION(server\FUNCTION);     side = SERVER;     init = INIT; }
#define ODIN_FUNCTION_DEDICATED(FUNCTION,INIT)  class FUNCTION { file = _FUNCTION(dedicated\FUNCTION);  side = DEDICATED;  init = INIT; }
#define ODIN_FUNCTION_NONPLAYER(FUNCTION,INIT)  class FUNCTION { file = _FUNCTION(dedicated\FUNCTION);  side = NONPLAYER;  init = INIT; }
#define ODIN_FUNCTION_CLIENT(FUNCTION,INIT)     class FUNCTION { file = _FUNCTION(client\FUNCTION);     side = CLIENT;     init = INIT; }
#define ODIN_FUNCTION_INTERFACE(FUNCTION,INIT)  class FUNCTION { file = _FUNCTION(interface\FUNCTION);  side = INTERFACE;  init = INIT; }
#define ODIN_FUNCTION_HEADLESS(FUNCTION,INIT)   class FUNCTION { file = _FUNCTION(headless\FUNCTION);   side = HEADLESS;   init = INIT; }
#define ODIN_FUNCTION_ALL(FUNCTION,INIT)        class FUNCTION { file = _FUNCTION(all\FUNCTION);        side = ALL;        init = INIT; }
#define ODIN_CONFIG(CONFIG)                     class CONFIG   { file = QUOTE(\PREFIX\MOD\addons\COMPONENT\config\CONFIG.sqf); }

#define SERVER      0
#define DEDICATED   1
#define NONPLAYER   2
#define CLIENT      3
#define INTERFACE   4
#define HEADLESS    5
#define ALL         6

// *.sqf - Access
#define VARIABLE(name)                          JOIN2(MOD_TAG,name)
#define COMPONENT_VARIABLE(name)                JOIN3(MOD_TAG,COMPONENT_CLASS,name)
#define FUNCTION(name)                          JOIN3(MOD_TAG,fnc,name)

// *.sqf - config
#define GET_ALL_CONFIG(CONFIG)                      (call { waitUntil { !isNil QUOTE(VARIABLE(config)); }; (VARIABLE(config) get QUOTE(CONFIG)); })
#define GET_CONFIG(CONFIG,KEY)                      (call { waitUntil { !isNil QUOTE(VARIABLE(config)); }; (VARIABLE(config) get QUOTE(CONFIG)) get KEY; })
#define GET_CONFIG_OR_DEFAULT(CONFIG,KEY,DEFAULT)   (call { waitUntil { !isNil QUOTE(VARIABLE(config)); }; (VARIABLE(config) get QUOTE(CONFIG)) getOrDefault [KEY, DEFAULT]; })
#define GET_CONFIG_NO_WAIT(CONFIG,KEY,DEFAULT)      if (isNil QUOTE(VARIABLE(config))) then { DEFAULT; } else { (VARIABLE(config) get QUOTE(CONFIG)) get KEY; }

// *.sqf - Staff
#define STAFF_VISITOR   0
#define STAFF_TRIAL     1
#define STAFF_JUNIOR    2
#define STAFF_SENIOR    3
#define STAFF_MANAGER   4
#define STAFF_CONSOLE   5

#define STAFF_ALL       9999

// *.sqf - Logging
#define LEVEL_TRACE 0
#define LEVEL_DEBUG 1
#define LEVEL_INFO  2
#define LEVEL_WARN  3
#define LEVEL_ERROR 4

#define LOG(LEVEL,LEVEL_TEXT,MESSAGE)                                           [LEVEL, [format [QUOTE([MOD_NAME] (COMPONENT_CLASS | %1) <%2 | LEVEL_TEXT>: ), _fnc_scriptName, [format ["Client %1: %2 (%3)", clientOwner, profileName, profileNameSteam], "Server"] select isServer] + MESSAGE]] call FUNCTION(log)
#define LOG1(LEVEL,LEVEL_TEXT,MESSAGE,ARG0)                                     [LEVEL, [format [QUOTE([MOD_NAME] (COMPONENT_CLASS | %1) <%2 | LEVEL_TEXT>: ), _fnc_scriptName, [format ["Client %1: %2 (%3)", clientOwner, profileName, profileNameSteam], "Server"] select isServer] + MESSAGE,ARG0]] call FUNCTION(log)
#define LOG2(LEVEL,LEVEL_TEXT,MESSAGE,ARG0,ARG1)                                [LEVEL, [format [QUOTE([MOD_NAME] (COMPONENT_CLASS | %1) <%2 | LEVEL_TEXT>: ), _fnc_scriptName, [format ["Client %1: %2 (%3)", clientOwner, profileName, profileNameSteam], "Server"] select isServer] + MESSAGE,ARG0,ARG1]] call FUNCTION(log)
#define LOG3(LEVEL,LEVEL_TEXT,MESSAGE,ARG0,ARG1,ARG2)                           [LEVEL, [format [QUOTE([MOD_NAME] (COMPONENT_CLASS | %1) <%2 | LEVEL_TEXT>: ), _fnc_scriptName, [format ["Client %1: %2 (%3)", clientOwner, profileName, profileNameSteam], "Server"] select isServer] + MESSAGE,ARG0,ARG1,ARG2]] call FUNCTION(log)
#define LOG4(LEVEL,LEVEL_TEXT,MESSAGE,ARG0,ARG1,ARG2,ARG3)                      [LEVEL, [format [QUOTE([MOD_NAME] (COMPONENT_CLASS | %1) <%2 | LEVEL_TEXT>: ), _fnc_scriptName, [format ["Client %1: %2 (%3)", clientOwner, profileName, profileNameSteam], "Server"] select isServer] + MESSAGE,ARG0,ARG1,ARG2,ARG3]] call FUNCTION(log)
#define LOG5(LEVEL,LEVEL_TEXT,MESSAGE,ARG0,ARG1,ARG2,ARG3,ARG4)                 [LEVEL, [format [QUOTE([MOD_NAME] (COMPONENT_CLASS | %1) <%2 | LEVEL_TEXT>: ), _fnc_scriptName, [format ["Client %1: %2 (%3)", clientOwner, profileName, profileNameSteam], "Server"] select isServer] + MESSAGE,ARG0,ARG1,ARG2,ARG3,ARG4]] call FUNCTION(log)
#define LOG6(LEVEL,LEVEL_TEXT,MESSAGE,ARG0,ARG1,ARG2,ARG3,ARG4,ARG5)            [LEVEL, [format [QUOTE([MOD_NAME] (COMPONENT_CLASS | %1) <%2 | LEVEL_TEXT>: ), _fnc_scriptName, [format ["Client %1: %2 (%3)", clientOwner, profileName, profileNameSteam], "Server"] select isServer] + MESSAGE,ARG0,ARG1,ARG2,ARG3,ARG4,ARG5]] call FUNCTION(log)
#define LOG7(LEVEL,LEVEL_TEXT,MESSAGE,ARG0,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6)       [LEVEL, [format [QUOTE([MOD_NAME] (COMPONENT_CLASS | %1) <%2 | LEVEL_TEXT>: ), _fnc_scriptName, [format ["Client %1: %2 (%3)", clientOwner, profileName, profileNameSteam], "Server"] select isServer] + MESSAGE,ARG0,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6]] call FUNCTION(log)
#define LOG8(LEVEL,LEVEL_TEXT,MESSAGE,ARG0,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7)  [LEVEL, [format [QUOTE([MOD_NAME] (COMPONENT_CLASS | %1) <%2 | LEVEL_TEXT>: ), _fnc_scriptName, [format ["Client %1: %2 (%3)", clientOwner, profileName, profileNameSteam], "Server"] select isServer] + MESSAGE,ARG0,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7]] call FUNCTION(log)

#define LOG_TRACE(MESSAGE)                                          LOG(0,TRACE,MESSAGE)
#define LOG_TRACE1(MESSAGE,ARG0)                                    LOG1(0,TRACE,MESSAGE,ARG0)
#define LOG_TRACE2(MESSAGE,ARG0,ARG1)                               LOG2(0,TRACE,MESSAGE,ARG0,ARG1)
#define LOG_TRACE3(MESSAGE,ARG0,ARG1,ARG2)                          LOG3(0,TRACE,MESSAGE,ARG0,ARG1,ARG2)
#define LOG_TRACE4(MESSAGE,ARG0,ARG1,ARG2,ARG3)                     LOG4(0,TRACE,MESSAGE,ARG0,ARG1,ARG2,ARG3)
#define LOG_TRACE5(MESSAGE,ARG0,ARG1,ARG2,ARG3,ARG4)                LOG5(0,TRACE,MESSAGE,ARG0,ARG1,ARG2,ARG3,ARG4)
#define LOG_TRACE6(MESSAGE,ARG0,ARG1,ARG2,ARG3,ARG4,ARG5)           LOG6(0,TRACE,MESSAGE,ARG0,ARG1,ARG2,ARG3,ARG4,ARG5)
#define LOG_TRACE7(MESSAGE,ARG0,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6)      LOG7(0,TRACE,MESSAGE,ARG0,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6)
#define LOG_TRACE8(MESSAGE,ARG0,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7) LOG8(0,TRACE,MESSAGE,ARG0,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7)

#define LOG_DEBUG(MESSAGE)                                          LOG(1,DEBUG,MESSAGE)
#define LOG_DEBUG1(MESSAGE,ARG0)                                    LOG1(1,DEBUG,MESSAGE,ARG0)
#define LOG_DEBUG2(MESSAGE,ARG0,ARG1)                               LOG2(1,DEBUG,MESSAGE,ARG0,ARG1)
#define LOG_DEBUG3(MESSAGE,ARG0,ARG1,ARG2)                          LOG3(1,DEBUG,MESSAGE,ARG0,ARG1,ARG2)
#define LOG_DEBUG4(MESSAGE,ARG0,ARG1,ARG2,ARG3)                     LOG4(1,DEBUG,MESSAGE,ARG0,ARG1,ARG2,ARG3)
#define LOG_DEBUG5(MESSAGE,ARG0,ARG1,ARG2,ARG3,ARG4)                LOG5(1,DEBUG,MESSAGE,ARG0,ARG1,ARG2,ARG3,ARG4)
#define LOG_DEBUG6(MESSAGE,ARG0,ARG1,ARG2,ARG3,ARG4,ARG5)           LOG6(1,DEBUG,MESSAGE,ARG0,ARG1,ARG2,ARG3,ARG4,ARG5)
#define LOG_DEBUG7(MESSAGE,ARG0,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6)      LOG7(1,DEBUG,MESSAGE,ARG0,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6)
#define LOG_DEBUG8(MESSAGE,ARG0,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7) LOG8(1,DEBUG,MESSAGE,ARG0,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7)

#define LOG_INFO(MESSAGE)                                           LOG(2,INFO ,MESSAGE)
#define LOG_INFO1(MESSAGE,ARG0)                                     LOG1(2,INFO ,MESSAGE,ARG0)
#define LOG_INFO2(MESSAGE,ARG0,ARG1)                                LOG2(2,INFO ,MESSAGE,ARG0,ARG1)
#define LOG_INFO3(MESSAGE,ARG0,ARG1,ARG2)                           LOG3(2,INFO ,MESSAGE,ARG0,ARG1,ARG2)
#define LOG_INFO4(MESSAGE,ARG0,ARG1,ARG2,ARG3)                      LOG4(2,INFO ,MESSAGE,ARG0,ARG1,ARG2,ARG3)
#define LOG_INFO5(MESSAGE,ARG0,ARG1,ARG2,ARG3,ARG4)                 LOG5(2,INFO ,MESSAGE,ARG0,ARG1,ARG2,ARG3,ARG4)
#define LOG_INFO6(MESSAGE,ARG0,ARG1,ARG2,ARG3,ARG4,ARG5)            LOG6(2,INFO ,MESSAGE,ARG0,ARG1,ARG2,ARG3,ARG4,ARG5)
#define LOG_INFO7(MESSAGE,ARG0,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6)       LOG7(2,INFO ,MESSAGE,ARG0,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6)
#define LOG_INFO8(MESSAGE,ARG0,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7)  LOG8(2,INFO ,MESSAGE,ARG0,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7)

#define LOG_WARN(MESSAGE)                                           LOG(3,WARN ,MESSAGE)
#define LOG_WARN1(MESSAGE,ARG0)                                     LOG1(3,WARN ,MESSAGE,ARG0)
#define LOG_WARN2(MESSAGE,ARG0,ARG1)                                LOG2(3,WARN ,MESSAGE,ARG0,ARG1)
#define LOG_WARN3(MESSAGE,ARG0,ARG1,ARG2)                           LOG3(3,WARN ,MESSAGE,ARG0,ARG1,ARG2)
#define LOG_WARN4(MESSAGE,ARG0,ARG1,ARG2,ARG3)                      LOG4(3,WARN ,MESSAGE,ARG0,ARG1,ARG2,ARG3)
#define LOG_WARN5(MESSAGE,ARG0,ARG1,ARG2,ARG3,ARG4)                 LOG5(3,WARN ,MESSAGE,ARG0,ARG1,ARG2,ARG3,ARG4)
#define LOG_WARN6(MESSAGE,ARG0,ARG1,ARG2,ARG3,ARG4,ARG5)            LOG6(3,WARN ,MESSAGE,ARG0,ARG1,ARG2,ARG3,ARG4,ARG5)
#define LOG_WARN7(MESSAGE,ARG0,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6)       LOG7(3,WARN ,MESSAGE,ARG0,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6)
#define LOG_WARN8(MESSAGE,ARG0,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7)  LOG8(3,WARN ,MESSAGE,ARG0,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7)

#define LOG_ERROR(MESSAGE)                                          LOG(4,ERROR,MESSAGE)
#define LOG_ERROR1(MESSAGE,ARG0)                                    LOG1(4,ERROR,MESSAGE,ARG0)
#define LOG_ERROR2(MESSAGE,ARG0,ARG1)                               LOG2(4,ERROR,MESSAGE,ARG0,ARG1)
#define LOG_ERROR3(MESSAGE,ARG0,ARG1,ARG2)                          LOG3(4,ERROR,MESSAGE,ARG0,ARG1,ARG2)
#define LOG_ERROR4(MESSAGE,ARG0,ARG1,ARG2,ARG3)                     LOG4(4,ERROR,MESSAGE,ARG0,ARG1,ARG2,ARG3)
#define LOG_ERROR5(MESSAGE,ARG0,ARG1,ARG2,ARG3,ARG4)                LOG5(4,ERROR,MESSAGE,ARG0,ARG1,ARG2,ARG3,ARG4)
#define LOG_ERROR6(MESSAGE,ARG0,ARG1,ARG2,ARG3,ARG4,ARG5)           LOG6(4,ERROR,MESSAGE,ARG0,ARG1,ARG2,ARG3,ARG4,ARG5)
#define LOG_ERROR7(MESSAGE,ARG0,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6)      LOG7(4,ERROR,MESSAGE,ARG0,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6)
#define LOG_ERROR8(MESSAGE,ARG0,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7) LOG8(4,ERROR,MESSAGE,ARG0,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7)
