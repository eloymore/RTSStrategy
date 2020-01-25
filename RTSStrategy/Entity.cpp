#include "Entity.h"
#include "Component.h"
#include "State.h"

void Entity::Copy(const Entity& entity) {
	name = entity.name;
	for (auto it = components.begin(); it != components.end(); ++it) {

	}
	game = entity.game;
}

// Copy constructor

// operator=

// Adds a component to the list of components of this entity
void Entity::AddComponent(Component* component)
{
	components.push_front(component);
	component->SetIterator(components.begin());
}

// Sends a message to the message center
void Entity::SendMessage(Message* message) const {
	game->AddMessage(message);
}