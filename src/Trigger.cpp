#include "vm205/Trigger.h"

namespace vm205 {

Trigger::Trigger():
	m_level(OSC_TRIGGER_LVL_CENTER),
	m_edge(OSC_TRIGGER_EDGE_RISING),
	m_enabled(false) {

}

}