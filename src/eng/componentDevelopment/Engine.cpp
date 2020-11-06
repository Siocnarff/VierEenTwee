#include "Engine.h"

using namespace eng;

void Engine::print() {
    pr::Doc::detail("\tEngine Quality: " + std::to_string(getQualityLabel()));
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
