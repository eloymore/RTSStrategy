#pragma once

#include "Entity.h"
#include "Message.h"
#include <list>
#include <stack>

class Game {
private:
	std::list<Entity> scene;
	std::stack<Message> messageStack;

	bool exit = false;

	void HandleEvents();
	void Update();
	void Render();
public:
	Game();
	Game(const Game& game);
	Game operator=(const Game& game);
	void Run();
	~Game();
};