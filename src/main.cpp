#include "hiveMind.h"

WorldManager worldManager;
HiveMind hiveMind(&worldManager.objectiveWorld);

int main() {
    worldManager.objectiveWorld.CreateLocation("KITCHEN");
    hiveMind.CreatePerson("PEARS", "KITCHEN");
    hiveMind.CreatePerson("DAVI", "KITCHEN");
    hiveMind.CreatePerson("DORI", "KITCHEN");
    hiveMind.CreatePerson("FLO", "KITCHEN");
    worldManager.objectiveWorld.Display();
}