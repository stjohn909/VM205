#include "vm205/Trace.h"

namespace vm205 {

Trace::Trace():
	m_size(800) {
	_points = new SDL_Point[m_size];
}

Trace::~Trace() {
	delete[] _points;
}

SDL_Point& Trace::point(int index) {
	return _points[index];
}

SDL_Point* Trace::points() {
	return _points;
}

int Trace::size() const {
	return m_size;
}

SDL_Point& Trace::operator[](int index) {
	return point(index);
}

}
