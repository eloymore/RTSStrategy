#pragma once

#include <SDL.h>
#include <list>
#include <stack>
#include "Entity.h"
#include "Message.h"

class State {
protected:
	std::list<Entity*> scene;
	std::stack<Message*> messageStack;

	bool exit = false;

	void Copy(const State& game);
	void Empty();

	virtual void HandleEvent(SDL_Event& event);
	virtual void Update();
	virtual void Render() const;
public:
	State();
	State(const State& game);
	State& operator=(const State& game);

	virtual void AddEntity(Entity* entity);
	virtual void RemoveEntity(Entity* entity);
	virtual void EraseEntity(std::list<Entity*>::iterator entity);

	virtual void AddMessage(Message* message);

	~State();
};