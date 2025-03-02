#pragma once
#include "world.h"

class Person {
public:
    Person(Object* thisPerson);
    void Display();
    Object* thisPerson;
    SubjectiveWorld world;
};

class HiveMind {
public:
    HiveMind(WorldManager* worldManager);
    void Display();
    void CreatePerson(std::string name);
    WorldManager* worldManager;
    std::vector<Person> people;
};