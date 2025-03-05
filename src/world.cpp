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
    thisLocation->attributes.AddAttribute(ATTRIBUTE_TYPE::INHABITANT, object.thisObject, true);
    object.attributes.AddAttribute(ATTRIBUTE_TYPE::PLACE, thisLocation->thisObject, true);
    inhabitants.push_back(&object);
}

void ObjectiveWorld::CreateLocation(std::string name) {
    Location* location = new Location(CreateObject(dataManager.EmitData(DATA_TYPE::LOCATION, name)));
    locations.push_back(location);
}

Location *ObjectiveWorld::GetLocation(std::string locationName) {
    DataPiece* thisLocation = dataManager.GetData(DATA_TYPE::LOCATION, locationName);
    for(Location* location : locations) {
        if(location->thisLocation->thisObject == thisLocation) {
            return location;
        }
    }
    return nullptr;
}