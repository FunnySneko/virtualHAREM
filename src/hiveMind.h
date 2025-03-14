#pragma once
#include "world.h"

class Person {
public:
    Person(Object* thisPerson);
    Object* thisPerson;
};

class HiveMind {
public:
    HiveMind(ObjectiveWorld* world);
    void CreatePerson(std::string name, std::string locationName, PERSON_ATTRIBUTE gender);
    ObjectiveWorld* world;
    std::vector<Person> people;
};