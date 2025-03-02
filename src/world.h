#pragma once
#include "data.h"
#include "object.h"

class World {
public:
    Object* CreateObject(DataPiece* thisObject);
    std::vector<Object> objects;
};

class ObjectiveWorld : public World {
public:
    DataManager dataManager;
};

class SubjectiveWorld : public World {
public:
    DataManagerSubjective* dataManager;
};

class WorldManager {
public:
    ObjectiveWorld objectiveWorld;
};