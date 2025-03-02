#include "hiveMind.h"

WorldManager worldManager;
HiveMind hiveMind(&worldManager);

int main() {
    hiveMind.CreatePerson("TEST_GUY_1");
    hiveMind.Display();
}