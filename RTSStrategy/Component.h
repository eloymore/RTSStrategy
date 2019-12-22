#pragma once

#include <stack>
#include <list>
#include <SDL.h>
class Message;
class Entity;
class Game;

class Component {
protected:
	std::stack<Message> messageQueue;
	Entity* entity;
	std::list<Component*>::iterator iterator;
	Game* game;
public:
	Component(Entity* entity, Game* game) : entity(entity), game(game) {};
	void SetIterator(std::list<Component*>::iterator it);
	virtual void Update() = 0;
	virtual void ProcessQueue() = 0;
	virtual void HandleEvent(const SDL_Event& event) = 0;
	virtual void Render() = 0;
	virtual void Receive(const Message& message) {
		messageQueue.push(message);
	};
	virtual ~Component() {};
};