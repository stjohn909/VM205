#include "vm205/Trigger.h"

namespace vm205 {

Trigger::Trigger():
	_level(OSC_TRIGGER_LVL_CENTER),
	_edge(OSC_TRIGGER_EDGE_RISING),
	_enabled(false) {

}

}