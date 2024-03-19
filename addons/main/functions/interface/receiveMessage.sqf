#include "script_component.hpp"
FIX_NAME
FIX_LINE_NUMBERS

waitUntil { !isNil QUOTE(VARIABLE(messageQueue)); };

VARIABLE(messageQueue) pushBack _this;

LOG_TRACE1("Received message: %1", _this)
