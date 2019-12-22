#include "State.h"
#include <SDL.h>

State::State()
{

}

// Copies all atributes from another game
void State::Copy(const State& game) {
	scene = game.scene;
	messageStack = game.messageStack;
	exit = game.exit;
}

// Empties the scene and message queue
void State::Empty() {
	// Scene
	for (auto it = scene.begin(); it != scene.end(); ++it) {
		delete* it;
	}

	// Message Queue
	Message* top = messageStack.top();
	while (!messageStack.empty()) {
		messageStack.pop();
		delete top;
		top = messageStack.top();
	}
}

State::State(const State& game)
{
	Copy(game);
}

State& State::operator=(const State& game) {
	if (this != &game) {
		Empty();
		Copy(game);
	}
	return *this;
}

// Adds the entity to the scene
void State::AddEntity(Entity* entity) {
	scene.push_front(entity);
	entity->SetIterator(scene.begin());
}

void State::RemoveEntity(Entity* entity) {
	for (auto it = scene.begin(); it != scene.end(); ++it) {
		if (*it == entity) {
			scene.remove(entity);
		}
	}
}

// Handles the event given by the app
void State::HandleEvent(SDL_Event& event) {
	for (auto it = scene.begin(); it != scene.end(); ++it) {
		(*it)->HandleEvent(event);
	}
}

// Updates the state of all entities in the scene
void State::Update() {
	for (auto it = scene.begin(); it != scene.end(); ++it) {
		(*it)->Update();
	}
}

// Makes a render call to all entities in the scene
void State::Render() const {
	for (auto it = scene.begin(); it != scene.end(); ++it) {
		(*it)->Render();
	}
}

State::~State() {
	Empty();
}
