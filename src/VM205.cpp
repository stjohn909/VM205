#include <bitset>
#include "VM205.h"

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

	// Set spi flags for correct VM205 operation
	uint32_t spi_flags = 0;
	std::bitset<32> bits(spi_flags);
	bits.set(1, true); // Sets to mode 2?
	int speed = 1000000;

	m_connection.open(speed, spi_flags);

	if (m_connection.spi_handle == PI_BAD_FLAGS)
	{
		printf("Bad flags.\n");
	}
	
	printf("SPI handle: %i\n", m_connection.spi_handle);

}


void VM205::transfer(char* txbuf, char* rxbuf, uint32_t count) {
	spi_xfer(m_connection.pi, m_connection.spi_handle, txbuf, rxbuf, count);
}


void VM205::disconnect() {
	m_connection.close();
}

void VM205::acquireData() {

	char in, out;
	
	out = OSC_GET_DATA;
	transfer(&out, &in, 1);

	out = OSC_GET_DATA_READY;
	do {
		SDL_Delay(20);
		transfer(&out, &in, 1);
	} while (in != OSC_DATA_READY);

	out = 0x01;
	transfer(&out, &in, 1); // garbage
	
	char in_array[800], out_array[800];

	for (int i=0; i<800; i++) out_array[i] = OSC_GET_SAMPLE;

	transfer(out_array, in_array, 801);

	for (int i=0; i<800; i++) m_data[i] = in_array[i];
}

void VM205::applySettings() {
	char in[2], out[2];

	out[0] = OSC_SET_VDIV;
	out[1] = 1 + (int)m_vdiv;
	transfer(out, in, 2);

	out[0] = OSC_SET_INPUT_COUPLING;
	out[1] = 1 + (int)m_inputCoupling;
	transfer(out, in, 2);
}

}