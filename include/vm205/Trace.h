/*
 * Copyright (C) 2015 Velleman nv
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 *
 */
/**
 * @file Trace.h
 * @brief 
 * @author Gunther Van Butsele
 */
#ifndef VM205_TRACE_H
#define VM205_TRACE_H

#include <SDL2/SDL.h>

namespace vm205 {

class Trace {
public:
	Trace();
	~Trace();
	SDL_Point& operator[](int index);
	int size() const;
	SDL_Point* points();
	SDL_Point& point(int index);
protected:
private:
	SDL_Point *_points;
	int _size;
};

}

#endif
