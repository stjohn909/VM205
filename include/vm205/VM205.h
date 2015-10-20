/*
 * Copyright (C) 2015 Velleman nv
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 *
 */
/**
 * @file Device.h
 * @brief 
 * @author Gunther Van Butsele
 */
#ifndef VM205_H
#define VM205_H

#include <SDL2/SDL.h>

#include "vm205/Protocol.h"
#include "vm205/Data.h"
#include "vm205/Trigger.h"

namespace vm205 {

typedef enum {
	OSC_VDIV_5V,
	OSC_VDIV_2V,
	OSC_VDIV_1V,
	OSC_VDIV_500mV,
	OSC_VDIV_200mV,
	OSC_VDIV_100mV
} VoltsPerDivision;

typedef enum {
	OSC_INPUT_COUPLING_AC,
	OSC_INPUT_COUPLING_DC
} InputCoupling;

typedef enum {
	OSC_TIMEBASE_200ms,
	OSC_TIMEBASE_100ms,
	OSC_TIMEBASE_50ms,
	OSC_TIMEBASE_20ms,
	OSC_TIMEBASE_10ms,
	OSC_TIMEBASE_5ms,
	OSC_TIMEBASE_2ms,
	OSC_TIMEBASE_1ms,
	OSC_TIMEBASE_500us,
	OSC_TIMEBASE_200us,
	OSC_TIMEBASE_100us,
	OSC_TIMEBASE_50us
} TimeBase;

typedef enum {
	OSC_YPOS_HIGH,
	OSC_YPOS_CENTER,
	OSC_YPOS_LOW
} YPosition;

class VM205 {
public:
	VM205();
	~VM205();
	void acquireData();
	void applySettings();
	Data& getData();
	void connect();
	void disconnect();
	VoltsPerDivision getVdiv() const;
	void setVdiv(VoltsPerDivision vdiv);
	InputCoupling getInputCoupling() const;
	void setInputCoupling(InputCoupling inputCoupling);
protected:
	void transfer(char* buf, uint32_t len);
	void transfer(char* tbuf, char* rbuf, uint32_t len);
	
	Data             _data;

	VoltsPerDivision _vdiv;
	TimeBase         _timebase;
	InputCoupling    _inputCoupling;
	Trigger          _trigger;
	YPosition        _ypos;
};

}

#endif
