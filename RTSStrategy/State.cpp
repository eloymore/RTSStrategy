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
	auto it = scene.begin();
	while (it != scene.end() && *it != entity) {
		++it;
	}
	if (it != scene.end()) {
		scene.erase(it);
	}
}

void State::EraseEntity(std::list<Entity*>::iterator entity) {
	scene.erase(entity);
}

// Handles the event given by the app
void State::HandleEvent(SDL_Event& event) {
	for (auto it = scene.begin(); it != scene.end(); ++it) {
		(*it)->HandleEvent(event);
	}
}

// Empties the message stack and updates the state of all entities in the scene 
void State::Update() {
	while (!messageStack.empty()) {
		Message* aux = messageStack.top();
		aux->receiver.message
		messageStack.pop();
	}

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

void State::AddMessage(Message* message) {
	messageStack.push(message);
}

State::~State() {
	Empty();
}
