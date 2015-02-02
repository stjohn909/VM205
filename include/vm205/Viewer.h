/*
 * Copyright (C) 2015 Velleman nv
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 *
 */
/**
 * @file Viewer.h
 * @brief 
 * @author Gunther Van Butsele
 */
#ifndef VM205_RENDERER_H
#define VM205_RENDERER_H

#include <SDL2/SDL.h>

#include "vm205/Trace.h"
#include "vm205/Data.h"
#include "vm205/VM205.h"

namespace vm205 {

#define SCREEN_WIDTH  1920
#define SCREEN_HEIGHT 1080

class Viewer {
public:
	Viewer(SDL_Renderer* renderer, VM205& device);
	~Viewer();
	const SDL_Rect& clientRect() const;
	void draw();
protected:
	void buildTrace();
private:
	SDL_Renderer*    _renderer;
	VM205&           _device;
	Trace            _trace;
	SDL_Rect         _clientRect;
	double           _dx;
	double           _dy;
};

}

#endif