#include "hiveMind.h"

WorldManager worldManager;
HiveMind hiveMind(&worldManager.objectiveWorld);

int main() {
    worldManager.objectiveWorld.CreateLocation("KITCHEN");
    hiveMind.CreatePerson("PEARS", "KITCHEN", PERSON_ATTRIBUTE::GENDER_MALE);
    hiveMind.CreatePerson("DAVI",  "KITCHEN", PERSON_ATTRIBUTE::GENDER_MALE);
    hiveMind.CreatePerson("DORI",  "KITCHEN", PERSON_ATTRIBUTE::GENDER_FEMALE);
    hiveMind.CreatePerson("FLO",   "KITCHEN", PERSON_ATTRIBUTE::GENDER_FEMALE);
    worldManager.objectiveWorld.Display();
    worldManager.objectiveWorld.dataManager.DisplayData();
}