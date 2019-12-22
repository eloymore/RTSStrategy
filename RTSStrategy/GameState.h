#pragma once

#include "State.h"

class GameState: public State {
public:
	GameState();
	GameState(const GameState& game);
	GameState& operator=(const GameState& game);
	~GameState();
};