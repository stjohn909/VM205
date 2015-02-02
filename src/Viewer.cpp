#include "vm205/Viewer.h"

namespace vm205 {

Viewer::Viewer(SDL_Renderer *renderer, VM205& device):
	_renderer(renderer), _device(device), _trace() {

	_clientRect.x = 0;
	_clientRect.y = 0;
	_clientRect.w = SCREEN_WIDTH;
	_clientRect.h = SCREEN_HEIGHT;

	_dx = SCREEN_WIDTH / (double)_trace.size();
	_dy = SCREEN_HEIGHT / 256.0;
}

Viewer::~Viewer() {
	
}

const SDL_Rect& Viewer::clientRect() const {

	return _clientRect;
}

void Viewer::buildTrace() {

	Data& data = _device.getData();

	for (int i = 0; i < _trace.size(); i++) {
		_trace[i].x = (i * _dx);
		_trace[i].y = (data[i] * _dy);
	}
}

void Viewer::draw() {

	SDL_SetRenderDrawColor(_renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);	
	SDL_RenderClear(_renderer);

	SDL_SetRenderDrawColor(_renderer, 0, 255, 0, SDL_ALPHA_OPAQUE);

	buildTrace();

	SDL_RenderDrawLines(_renderer, _trace.points(), _trace.size());
	SDL_RenderPresent(_renderer);
}

}