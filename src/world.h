#pragma once
#include "data.h"
#include "object.h"

class Location {
public:
    Location(Object* thisLocation);
    void AddInhabitant(Object& object);
    Object* thisLocation;
    std::vector<Object*> inhabitants;
};

class World {
public:
    void Display();
    virtual void CreateLocation(std::string name) = 0;
    Object* CreateObject(DataPiece* thisObject);
    virtual Location* GetLocation(std::string locationName) = 0;
    std::vector<Object*> objects;
    std::vector<Location*> locations;
};

class ObjectiveWorld : public World {
public:
    void CreateLocation(std::string name) override;
    Location* GetLocation(std::string locationName) override;
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