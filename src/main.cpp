#include <list>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include <getopt.h>

#include "vm205/VM205.h"
#include "vm205/Viewer.h"

using namespace vm205;

int main(int argc, char **argv) {


	// First we need to know which interface we will use to create a pigpio SPI
	// connection.  As root or sudo, we can connect directly to the SPI bus through pigpio, 
	// or as a non-privileged user, we can connect through the pigpio daemon (pigpiod),
	// if it's available, but we don't use the daemon by default because we don't support
	// detection of a pigpiod process.
	bool daemon = false;

	// Parse the input args to set use_daemon. If the -d flag is present, 
	// set use_daemon to true, which will open a connection to the SPI bus
	// via the pigpio daemon.  This is the most convenient mode for fast
	// test iteration.
	int arg;
	int err = 0;
	static char usage[] = "usage: %s [-d] [-h] \n";
	while ((arg = getopt(argc, argv, "dh")) != -1)
		switch (arg) {
			case 'd':
				daemon = true;
				break;
			case 'h':
				fprintf(stderr, usage, argv[0]);
				err++;
		}
	if(err > 0)
		return 1;

	
	// VM 205 hardware initialization and connection
	VM205 shield;
	shield.connection.setdaemon(daemon);
	shield.connection.sethostname("localhost");
	shield.connect();
	
	
	// Since we're not drawing anything right now, all we care about is events.
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {
	//if (SDL_Init(SDL_INIT_EVENTS) == -1){
		std::cout << SDL_GetError() << std::endl;
		return 1;
	}
	

	// TODO: Implement a GUI.  Current candidates are libagar and Qt,
	// but cross-compiling Qt is proving to be a challenge, and a 1GB
	// RPi is not a good Qt dev machine.
	
	SDL_Window *win = nullptr;
	// SDL_WINDOW_FULLSCREEN | SDL_WINDOW_INPUT_GRABBED
	win = SDL_CreateWindow(
		"VM205 with pigpio",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		1280,
		720,
		SDL_WINDOW_RESIZABLE
	);
	if (win == nullptr){
		std::cout << SDL_GetError() << std::endl;
		return 1;
	}
	
	SDL_Renderer *renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == nullptr){
		std::cout << SDL_GetError() << std::endl;
		return 1;
	}
	

	Viewer viewer(renderer, shield);
	bool done = false;
	
	while (!done) {
		SDL_Event e;
		while(SDL_PollEvent(&e) != 0) {
			switch(e.type) {
				case SDL_QUIT:
					done = true;
					break;
				case SDL_KEYDOWN:
					switch(e.key.keysym.sym) {
						
						case SDLK_ESCAPE:
							done = true;
							break;
						case SDLK_1: shield.setVdiv(OSC_VDIV_5V); break;
						case SDLK_2: shield.setVdiv(OSC_VDIV_2V); break;
						case SDLK_3: shield.setVdiv(OSC_VDIV_1V); break;
						case SDLK_4: shield.setVdiv(OSC_VDIV_500mV); break;
						case SDLK_5: shield.setVdiv(OSC_VDIV_200mV); break;
						case SDLK_6: shield.setVdiv(OSC_VDIV_100mV); break;
						case SDLK_a: shield.setInputCoupling(OSC_INPUT_COUPLING_AC); break;
						case SDLK_d: shield.setInputCoupling(OSC_INPUT_COUPLING_DC); break;
						case SDLK_t: shield.setTrigger(); break;

					
					}	
					shield.applySettings();
					break;
			}
		}
		if (shield.getRun() == false)
			shield.acquireData();
			
		viewer.draw();
	}
	

	shield.disconnect();

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(win);
	SDL_Quit();
	
	return 0;
}


