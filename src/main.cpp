#include "hiveMind.h"

WorldManager worldManager;
HiveMind hiveMind(&worldManager.objectiveWorld);

int main() {
    hiveMind.CreatePerson("TEST_GUY_1");
    hiveMind.CreatePerson("TEST_GUY_2");
    hiveMind.CreatePerson("TEST_GUY_3");
    worldManager.objectiveWorld.Display();
}