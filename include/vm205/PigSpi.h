/*
This class encapsulates a pigpio connection.  We
support both the pigpio and the pigpiod interfaces.
For a successful pigpio connection, the main function
must be running as root or sudo.  No elevated privilege
is necessary for a pigpiod connection.
*/

#ifndef PIGSPI_H
#define PIGSPI_H

#include <pigpio.h>
#include <pigpiod_if2.h>
#include <stdio.h>

namespace vm205 {

class PigSpi {
	public:
		PigSpi();
		~PigSpi();
		void 	setdaemon(bool daemon);
		bool	getdaemon();
		int		getspihandle();
		void 	start();
		void 	stop();
		void 	open(int baud);
		void 	close();
	private:
		int m_spi_handle = -1;
		int m_daemon = false;	
};
	
}

#endif