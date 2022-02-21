#include <list>
#include <iostream>

#include "vm205/VM205.h"
#include "vm205/Viewer.h"

using namespace vm205;

int main(int argc, char** argv) {
	
	if (SDL_Init(SDL_INIT_EVENTS) == -1){
		std::cout << SDL_GetError() << std::endl;
		return 1;
	}
	
	/*
	SDL_Window *win = nullptr;
	// //SDL_WINDOW_FULLSCREEN | SDL_WINDOW_INPUT_GRABBED
	win = SDL_CreateWindow(
		"VM205 demo!",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		SCREEN_WIDTH,
		SCREEN_HEIGHT,
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
	*/
	VM205 shield;
	shield.connect();

	//Viewer viewer(renderer, shield);

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
					}
					shield.applySettings();
					break;
			}
		}
		shield.acquireData();  // Uncomment this when the board is delivered.
		//sleep(1);
		//viewer.draw();
	}

	shield.disconnect();
	
	/*
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(win);
	SDL_Quit();
	*/
	return 0;
}
