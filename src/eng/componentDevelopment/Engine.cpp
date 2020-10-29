#include "Engine.h"

using namespace eng;

void Engine::print() {
	std::cout << "Engine" << std::endl;
}

Engine::Engine(Component *toClone) : Component(toClone) {}

Component *Engine::clone() {
    return new Engine(this);
}