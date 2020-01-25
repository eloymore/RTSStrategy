#include "Component.h"
#include "State.h"

void Component::SetIterator(std::list<Component*>::iterator it) {
	iterator = it;
}