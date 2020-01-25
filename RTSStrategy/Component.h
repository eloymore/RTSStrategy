#pragma once

#include <list>
#include <SDL.h>
class Message;
class Entity;

class Component {
protected:
	Entity* entity;
	std::list<Component*>::iterator iterator;

	virtual void Copy(const Component& component) = 0;
public:
	Component(Entity* entity) : entity(entity) {};
	void SetIterator(std::list<Component*>::iterator it);
	virtual void HandleEvent(const SDL_Event& event) = 0;
	virtual void Update() = 0;
	virtual void Render() const = 0;
	virtual void ReceiveMessage(Message* message) = 0;
	virtual ~Component() {};
};