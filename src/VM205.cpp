#include "vm205/VM205.h"

#include "bcm2835.h"

namespace vm205 {

VM205::VM205():
	_data(800),
	_vdiv(OSC_VDIV_5V),
	_timebase(OSC_TIMEBASE_50us),
	_inputCoupling(OSC_INPUT_COUPLING_AC),
	_ypos(OSC_YPOS_CENTER) {
	
	bcm2835_init();
}

VM205::~VM205() {
	bcm2835_close();
}

Data& VM205::getData() {
	return _data;
}

VoltsPerDivision VM205::getVdiv() const {
	return _vdiv;
}

void VM205::setVdiv(VoltsPerDivision vdiv) {
	_vdiv = vdiv;
}

InputCoupling VM205::getInputCoupling() const {
	return _inputCoupling;
}

void VM205::setInputCoupling(InputCoupling inputCoupling) {
	_inputCoupling = inputCoupling;
}

void VM205::connect() {
	bcm2835_spi_begin();
	bcm2835_spi_setDataMode(BCM2835_SPI_MODE2);
	bcm2835_spi_chipSelect(BCM2835_SPI_CS0);
	bcm2835_spi_setBitOrder(BCM2835_SPI_BIT_ORDER_MSBFIRST);
	bcm2835_spi_setClockDivider(500);
}

void VM205::transfer(char* buf, uint32_t len) {
	bcm2835_spi_transfern(buf, len);
}

void VM205::transfer(char* tbuf, char* rbuf, uint32_t len) {
	bcm2835_spi_transfernb(tbuf, rbuf, len);
}

void VM205::disconnect() {
	bcm2835_spi_end();
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

	for (int i=0; i<800; i++) _data[i] = in_array[i];
}

void VM205::applySettings() {
	char in[2], out[2];

	out[0] = OSC_SET_VDIV;
	out[1] = 1 + (int)_vdiv;
	transfer(out, in, 2);

	out[0] = OSC_SET_INPUT_COUPLING;
	out[1] = 1 + (int)_inputCoupling;
	transfer(out, in, 2);
}

}