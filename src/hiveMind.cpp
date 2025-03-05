#include "hiveMind.h"

Person::Person(Object *thisPerson) {
    this->thisPerson = thisPerson;
}

HiveMind::HiveMind(ObjectiveWorld *world) {
    this->world = world;
}

void HiveMind::CreatePerson(std::string name) {
    Person person(world->CreateObject(world->dataManager.EmitData(DATA_TYPE::PERSON, name)));
    person.thisPerson->attributes.AddAttribute(ATTRIBUTE_TYPE::SELF, person.thisPerson->thisObject, true);
    people.push_back(person);
}