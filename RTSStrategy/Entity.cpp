#include "Entity.h"
#include "Component.h"

// Copy constructor

// operator=

// Adds a component to the list of components of this entity
void Entity::AddComponent(Component* component)
{
	components.push_front(component);
	component->SetIterator(components.begin());
}
