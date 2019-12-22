#pragma once

class Entity;

class Message {
public:
	Entity* receiver;	// Or receivers

	Message(Entity* receiver) : receiver(receiver) {};
	virtual ~Message() {};
};