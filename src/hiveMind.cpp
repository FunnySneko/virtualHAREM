#include "hiveMind.h"

Person::Person(Object *thisPerson) {
    this->thisPerson = thisPerson;
}

HiveMind::HiveMind(ObjectiveWorld *world) {
    this->world = world;
}

void HiveMind::CreatePerson(std::string name, std::string locationName) {
    Person person(world->CreateObject(world->dataManager.EmitData(DATA_TYPE::PERSON, name)));
    Location* location = world->GetLocation(locationName);
    location->AddInhabitant(*person.thisPerson);
    people.push_back(person);
}