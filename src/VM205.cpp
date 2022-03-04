#include "vm205/VM205.h"
#include <strings.h>

namespace vm205 {

VM205::VM205():
	m_data(800),
	m_vdiv(OSC_VDIV_5V),
	m_timebase(OSC_TIMEBASE_50us),
	m_inputCoupling(OSC_INPUT_COUPLING_AC),
	m_ypos(OSC_YPOS_CENTER),
	m_trigger(),
	m_run()
	{	
	}


VM205::~VM205() {
	connection.stop();
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

	printf("Using pigpio daemon: %i\n", connection.getdaemon());
	connection.start();
	connection.open(1000000);  // SPI is hard set to Mode 2.
	if (connection.getspihandle() == PI_BAD_FLAGS)
	{
		printf("Bad flags.\n");
	}
	printf("SPI handle: %i\n", connection.getspihandle());
}


void VM205::transfer(char* txbuf, char* rxbuf, uint32_t count) {

	if (this->connection.getdaemon() == true)
	{
		spi_xfer(0, connection.getspihandle(), txbuf, rxbuf, count);
		return;
	}
	spiXfer(connection.getspihandle(), txbuf, rxbuf, count);

}

void VM205::disconnect() {
	connection.close();
	connection.stop();
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
		transfer(&out, &in, 1);

	} while (in != OSC_DATA_READY );

	// if(in == OSC_DATA_READY)
	// 	printf("Data is Ready: %#02x\n", in);

	out = 0x01;
	transfer(&out, &in, 1); // garbage
	
	char in_array[800], out_array[800];
	
	for (int i=0; i<800; i++) 
		out_array[i] = OSC_GET_SAMPLE;

	transfer(out_array, in_array, 801);

	//printf("\nBegin received data\n");
	for (int i=0; i<800; i++)
	{
		m_data[i] = in_array[i];
		//printf("%#02x", m_data[i]);
	}
	//printf("\nEnd of received data\n");
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
}

void VM205::setTrigger() {
	m_trigger.enabled = !m_trigger.enabled;
	char in[2], out[2];
	out[0] = OSC_SET_TRIGGER;

	out[1] = 1 + ((int)m_trigger.enabled); // should be 0x01 or 0x02
 	printf ("Trigger enabled: %x\n", m_trigger.enabled);
	transfer(out, in, 2);
}

bool VM205::getRun() { return m_run;}

bool VM205::runStop() { return !m_run; }

}
