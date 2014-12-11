#include <stdio.h>
#include "vm205/vm205.h"

int main(int argc, char *argv[])
{
	vm205_buffer_t buffer;
	int i;

	vm205_init();
	vm205_set(VM205_SET_COUPLING, VM205_COUPLING_DC);

	vm205_acquire(&buffer);

	for (i=0; i<VM205_MAX_SAMPLES; i++) {
		printf("%d,", buffer.samples[i]);
	}

	vm205_quit();
		
	return 0;
}
