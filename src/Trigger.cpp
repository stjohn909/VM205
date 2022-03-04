#include "vm205/Trigger.h"

namespace vm205 {

Trigger::Trigger():
	level(OSC_TRIGGER_LVL_CENTER),
	edge(OSC_TRIGGER_EDGE_RISING),
	enabled(false) {

}

}