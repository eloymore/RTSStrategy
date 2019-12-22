#pragma once

#include <list>
#include <SDL.h>
class Component;


class Entity {
protected:
	std::list<Component*> components;
public:
	Entity() {};
	Entity(const Entity& entity);
	Entity operator=(const Entity& entity);
	void AddComponent(Component* component);
	void RemoveComponent(Component* component);
	void EraseComponent(std::list<Component*>::iterator component);
	virtual void Update();
	virtual void HandleEvent(const SDL_Event& event);
	virtual void Render();
	~Entity();
};