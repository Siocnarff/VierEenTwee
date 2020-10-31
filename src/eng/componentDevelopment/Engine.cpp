#include "Engine.h"

using namespace eng;

void Engine::print() {
    std::cout   << "        Engine Quality: " << getQualityLabel() << std::endl;
}

Engine::Engine(Component *toClone) : Component(toClone) {}

Component *Engine::clone() {
    return new Engine(this);
}

int Engine::getId() {
    return 1;
}

Engine::Engine(int quality) : Component(quality) {

}
