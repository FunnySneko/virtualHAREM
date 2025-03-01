#pragma once
#include "person.h"
#include "data.h"

class HiveMind {
public:
    HiveMind(DataManager* dataManager);
    void Display();
    Person CreatePerson(std::string name);
private:
    std::vector<Person> people;
    DataManager* dataManager;
};