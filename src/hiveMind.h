#pragma once
#include "world.h"

class Person {
public:
    Person(Object* thisPerson);
    Object* thisPerson;
    SubjectiveWorld subjectiveWorld;
};

class HiveMind {
public:
    HiveMind(ObjectiveWorld* world);
    void CreatePerson(std::string name);
    ObjectiveWorld* world;
    std::vector<Person> people;
};