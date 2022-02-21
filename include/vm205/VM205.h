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
#include <pigpio.h>

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

struct PigpioSpiConnection {
	int pi = -1;
	int spi_handle = -1;

	// We will always connect to the local
	// host and port at 0,0 because we're 
	// accessing GPIO-connected hardware.
	void start() {
		gpioInitialise();
	}
	void stop() {
		gpioTerminate();
	}
	void open(int s_baud) {
		spi_handle = spiOpen(0, s_baud, PI_SPI_FLAGS_MODE(2));
	}
	void close() {
		spiClose(spi_handle);
	};
};

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
	void transfer(char* txbuf, char* rxbuf, uint32_t count);
	
	PigpioSpiConnection m_connection;
	Data             	m_data;
	VoltsPerDivision 	m_vdiv;
	TimeBase         	m_timebase;
	InputCoupling    	m_inputCoupling;
	Trigger          	m_trigger;
	YPosition        	m_ypos;
};

}

#endif
