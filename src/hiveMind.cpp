#include "hiveMind.h"

HiveMind::HiveMind(DataManager *dataManager) {
    this->dataManager = dataManager;
}

void HiveMind::Display() {
    for (Person& person : people) {
        person.Display();
    }
}

Person HiveMind::CreatePerson(std::string name)
{
    Person person(dataManager->EmitData(DATA_TYPE::PERSON, name));
    people.push_back(person);
}