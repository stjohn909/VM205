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
	OSC_TRIGGER_LVL_HIGH = 0x00,
	OSC_TRIGGER_LVL_CENTER = 0xff,
	OSC_TRIGGER_LVL_LOW = 0x7f
} TriggerLevel;


typedef enum {
	OSC_TRIGGER_EDGE_RISING = 0x03,
	OSC_TRIGGER_EDGE_FALLING 
} TriggerEdge;

class Trigger {
public:
	Trigger();
	TriggerLevel 	level;
	TriggerEdge 	edge;
	bool			enabled;
protected:
private:

};

}

#endif