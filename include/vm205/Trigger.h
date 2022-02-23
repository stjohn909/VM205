/*
 * Copyright (C) 2015 Velleman nv
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 *
 */
/**
 * @file Trigger.h
 * @brief 
 * @author Gunther Van Butsele
 */
#ifndef VM205_TRIGGER_H
#define VM205_TRIGGER_H

namespace vm205 {

typedef enum {
	OSC_TRIGGER_LVL_HIGH,
	OSC_TRIGGER_LVL_CENTER,
	OSC_TRIGGER_LVL_LOW
} TriggerLevel;

typedef enum {
	OSC_TRIGGER_EDGE_RISING,
	OSC_TRIGGER_EDGE_FALLING
} TriggerEdge;

class Trigger {
public:
	Trigger();
protected:
private:
	TriggerLevel m_level;
	TriggerEdge  m_edge;
	bool         m_enabled;
};

}

#endif