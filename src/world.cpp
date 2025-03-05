#include "world.h"

void World::Display(){
    for(Object* object : objects) {
        object->Display();
    }
}

Object *World::CreateObject(DataPiece *thisObject) {
    Object* object = new Object(thisObject);
    objects.push_back(object);
    return objects.back();
}

Location::Location(Object *thisLocation) {
    this->thisLocation = thisLocation;
}

void Location::AddInhabitant(Object &object) {
    inhabitants.push_back(thisLocation->attributes.AddAttribute(ATTRIBUTE_TYPE::INHABITANT, object.thisObject, true));
}