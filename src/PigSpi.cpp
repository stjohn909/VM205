#include "vm205/PigSpi.h"

namespace vm205 {
PigSpi::PigSpi():
	m_spi_handle(),
	m_daemon()
	{}

PigSpi::~PigSpi() {	

}

void PigSpi::setdaemon(bool daemon)
{
	m_daemon = daemon;
}

bool PigSpi::getdaemon()
{
	return m_daemon;
}
	
void PigSpi::start() {
	if (m_daemon == true)
	{
		printf("Congrats, you're using pigpiod!\n");
		// "0,0" means "start pigpio on the local host and port."
		pigpio_start(0,0);
		return;
	}
	gpioInitialise();
}

void PigSpi::stop() {
	if(m_daemon == true)
	{
		pigpio_stop(0);
		return;
	}
	gpioTerminate();
}

void PigSpi::open(int baud) {
	if (m_daemon == true)
	{
		m_spi_handle = spi_open(0, 0, baud, PI_SPI_FLAGS_MODE(2));
		return;
	}
	m_spi_handle = spiOpen(0, baud, PI_SPI_FLAGS_MODE(2));
}

void PigSpi::close() {
	if (m_daemon == true)
	{
		spi_close(0, m_spi_handle);
		return;
	}
	spiClose(m_spi_handle);
}

int PigSpi::getspihandle() {
	return m_spi_handle;
}

}