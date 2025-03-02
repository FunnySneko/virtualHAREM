#include "hiveMind.h"

Person::Person(Object *thisPerson) {
    this->thisPerson = thisPerson;
}

void Person::Display() {
    thisPerson->thisObject->Display("NAME");
}

HiveMind::HiveMind(WorldManager *worldManager) {
    this->worldManager = worldManager;
}

void HiveMind::Display() {
    for (Person& person : people) {
        person.Display();
    }
}

void HiveMind::CreatePerson(std::string name)
{
    Person person(worldManager->objectiveWorld.CreateObject(worldManager->objectiveWorld.dataManager.EmitData(DATA_TYPE::PERSON, name)));
    people.push_back(person);
}