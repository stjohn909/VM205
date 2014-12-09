/*
 * Copyright (C) 2014 Velleman nv
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 *
 */
#include "vm205/vm205.h"

#include <bcm2835.h>
#include <unistd.h>
#include <stdio.h>

VM205_DECLARE(void) vm205_init()
{
	bcm2835_init();
	bcm2835_spi_begin();
	bcm2835_spi_setDataMode(BCM2835_SPI_MODE2);
	bcm2835_spi_chipSelect(BCM2835_SPI_CS0);
	bcm2835_spi_setBitOrder(BCM2835_SPI_BIT_ORDER_MSBFIRST);
	bcm2835_spi_setClockDivider(500);
}

VM205_DECLARE(void) vm205_set(
	unsigned char setting,
	unsigned char value)
{
	char in[2], out[2];
	
	out[0] = setting;
	out[1] = value;
	
	bcm2835_spi_transfernb(out, in, 2);
}

VM205_DECLARE(unsigned char) vm205_cmd(
	unsigned char cmd)
{
	char in, out = cmd;
	
	bcm2835_spi_transfernb(&out, &in, 1);

	return in;
}

VM205_DECLARE(void) vm205_acquire(vm205_buffer_t *buffer)
{
	int i;
	
	// Instruct the vm205 to start acquiring samples.
	vm205_cmd(VM205_GET_SAMPLES);

	// Loop until the vm205 has acquired all samples.
	char result;
	do {
		result = vm205_cmd(VM205_GET_STATUS);
		usleep(20 * 1000);
	}
	while (result != VM205_READY);

	// The next sample will be garbage from the previous loop.
	vm205_cmd(VM205_GET_SAMPLE);

	// Get all 800 samples.
	memset(buffer->samples, VM205_GET_SAMPLE, VM205_MAX_SAMPLES);
	bcm2835_spi_transfernb(buffer->samples, buffer->samples, VM205_MAX_SAMPLES);
}

VM205_DECLARE(void) vm205_quit()
{
	bcm2835_spi_end();
	bcm2835_close();
}