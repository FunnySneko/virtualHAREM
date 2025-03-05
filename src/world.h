#pragma once
#include "data.h"
#include "object.h"

class World {
public:
    void Display();
    Object* CreateObject(DataPiece* thisObject);
    std::vector<Object*> objects;
};

class ObjectiveWorld : public World {
public:
    DataManager dataManager;
};

class SubjectiveWorld : public World {
public:
    DataManagerSubjective* dataManager;
};

class Location {
public:
    Location(Object* thisLocation);
    void AddInhabitant(Object& object);
    Object* thisLocation;
    std::vector<Attribute*> inhabitants;
};

class WorldManager {
public:
    ObjectiveWorld objectiveWorld;
};