#include <bitset>
#include "vm205/VM205.h"
#include <pigpiod_if2.h>

namespace vm205 {

VM205::VM205():
	m_data(800),
	m_vdiv(OSC_VDIV_5V),
	m_timebase(OSC_TIMEBASE_50us),
	m_inputCoupling(OSC_INPUT_COUPLING_AC),
	m_ypos(OSC_YPOS_CENTER)
	{ 
		m_connection.start();
	}

VM205::~VM205() {
	m_connection.stop();
}

Data& VM205::getData() {
	return m_data;
}

VoltsPerDivision VM205::getVdiv() const {
	return m_vdiv;
}

void VM205::setVdiv(VoltsPerDivision vdiv) {
	m_vdiv = vdiv;
}

InputCoupling VM205::getInputCoupling() const {
	return m_inputCoupling;
}

void VM205::setInputCoupling(InputCoupling inputCoupling) {
	m_inputCoupling = inputCoupling;
}


void VM205::connect() {

	/*
	// Set spi flags for correct VM205 operation
	uint32_t spi_flags = 0;
	std::bitset<32> bits(spi_flags);
	bits.set(1, true); // Sets to mode 2?

	int speed = 100000;
	//spi_flags = 000000110010;
	*/

	m_connection.open(50000);

	if (m_connection.spi_handle == PI_BAD_FLAGS)
	{
		printf("Bad flags.\n");
	}
	
	printf("SPI handle: %i\n", m_connection.spi_handle);

}


void VM205::transfer(char* txbuf, char* rxbuf, uint32_t count) {
	spiXfer(m_connection.spi_handle, txbuf, rxbuf, count);

}


void VM205::disconnect() {
	m_connection.close();
}


void VM205::acquireData() {
	//printf("Acquiring Data....\n");
	char in, out;
	
	out = OSC_GET_DATA;
	//printf("Get data: %#02x\n", out);
	transfer(&out, &in, 1);

	out = OSC_GET_DATA_READY;
	//printf("Getting Data ready: %#02x\n", out);

	do {
		SDL_Delay(20);
		//printf("Transferring....\n");
		transfer(&out, &in, 1);
		//printf("Transfer in: %#02x\n", in);
		//safety_out++;
	} while (in != OSC_DATA_READY );

	// if(in == OSC_DATA_READY)
	// 	printf("Data is Ready: %#02x\n", in);

	out = 0x01;
	transfer(&out, &in, 1); // garbage
	
	char in_array[800], out_array[800];
	
	for (int i=0; i<800; i++) 
		out_array[i] = OSC_GET_SAMPLE;

	transfer(out_array, in_array, 801);

	printf("\nBegin received data\n");
	for (int i=0; i<800; i++)
	{
		m_data[i] = in_array[i];
		printf("%#02x", m_data[i]);
	}

	printf("\nEnd of received data\n");
}

void VM205::applySettings() {
	char in[2], out[2];
	printf("Applying settings...\n");

	out[0] = OSC_SET_VDIV;
	out[1] = 1 + (int)m_vdiv;
	transfer(out, in, 2);

	out[0] = OSC_SET_INPUT_COUPLING;
	out[1] = 1 + (int)m_inputCoupling;
	transfer(out, in, 2);
	printf("Settings applied...\n");
}

}