#pragma once

#include <list>
#include <SDL.h>
#include <string>
#include <stack>
class Component;
class Message;

class Entity {
protected:
	std::string name;
	std::list<Component*> components;
	std::stack<Message*> messageQueue;
	std::list<Entity*>::iterator iterator;
	State* game;

	void Copy(const Entity& entity);
	void Clear();
public:
	Entity(std::string name) : name(name) {};
	Entity(const Entity& entity);
	Entity operator=(const Entity& entity);
	void SetIterator(std::list<Entity*>::iterator it);

	void SetName(std::string name);

	void AddComponent(Component* component);
	void RemoveComponent(Component* component);
	void EraseComponent(std::list<Component*>::iterator component);

	virtual void Update();
	virtual void HandleEvent(const SDL_Event& event);
	virtual void Render() const;

	// Sends a message to another entity (through the message center)
	virtual void SendMessage(Message* message) const;
	~Entity();
};