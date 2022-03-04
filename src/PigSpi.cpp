#include "vm205/PigSpi.h"

namespace vm205 {
PigSpi::PigSpi():
	m_spi_handle(),
	m_daemon(),
	m_pi()
	{}

PigSpi::~PigSpi() {	
	this->stop();
}

int PigSpi::getpi() {
	return m_pi;
}

void PigSpi::setdaemon(bool daemon) {
	m_daemon = daemon;
}


bool PigSpi::getdaemon() {
	return m_daemon;
}


void PigSpi::sethostname(string name) {
	// Returns a valid host parameter for 
	// starting a new pigpiod connection.
	m_hostname = name.c_str();
}

void PigSpi::start() {

	if (m_daemon == true)
	{
		sethostname(this->hostname);
		printf("Congrats, you're using pigpiod!\n");
		m_pi = pigpio_start(m_hostname, 0);

		return;
	}
	gpioInitialise();
}

void PigSpi::stop() {
	if (m_spi_handle >= 0)
		this->close();

	if(m_daemon == true)
	{
		pigpio_stop(m_pi);
		return;
	}
	gpioTerminate();
}

void PigSpi::open(int baud) {
	// SPI channel is 0 since we don't need any of the
	// features of aux SPI's, and there's no GPIO 
	// pass-through on the VM205 -- It's a shield, not a hat.
	if (m_daemon == true)
	{	
		m_spi_handle = spi_open(m_pi, 0, baud, PI_SPI_FLAGS_MODE(2));
		return;
	}
	m_spi_handle = spiOpen(m_pi, baud, PI_SPI_FLAGS_MODE(2));
}

void PigSpi::close() {
	if (m_daemon == true)
	{
		spi_close(m_pi, m_spi_handle);
		return;
	}
	spiClose(m_spi_handle);
}

int PigSpi::getspihandle() {
	return m_spi_handle;
}

}