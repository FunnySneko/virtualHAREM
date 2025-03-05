#include "hiveMind.h"

Person::Person(Object *thisPerson) {
    this->thisPerson = thisPerson;
}

HiveMind::HiveMind(ObjectiveWorld *world) {
    this->world = world;
}

void HiveMind::CreatePerson(std::string name, std::string locationName, PERSON_ATTRIBUTE gender) {
    if (gender == PERSON_ATTRIBUTE::GENDER_MALE || gender == PERSON_ATTRIBUTE::GENDER_FEMALE) {
        Person person(world->CreateObject(world->dataManager.EmitData(DATA_TYPE::PERSON, name)));
        Location* location = world->GetLocation(locationName);
        if(location != nullptr) {
            location->AddInhabitant(*person.thisPerson);
            person.thisPerson->attributes.AddAttribute(ATTRIBUTE_TYPE::GENDER, world->dataManager.GetData(DATA_TYPE::PERSON_ATTRIBUTE, personAttributeNames[int(gender)]), true);
            people.push_back(person);
        }
    }
}