#pragma once

class Entity;

class Message {
protected:
	virtual void Copy(const Message& message) {
		receiver = message.receiver;
	};
	virtual void Clear() {};
public:
	Entity* receiver;

	Message() : receiver(nullptr) {};
	Message(Entity* receiver) : receiver(receiver) {};
	Message(const Message& message) {
		Copy(message);
	};
	Message* operator=(const Message& message) {
		if (this != &message) {
			Clear();
			Copy(message);
		}
		return this;
	};
	virtual ~Message() {
		Clear();
	};
};