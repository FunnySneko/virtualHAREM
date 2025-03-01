#include "virtualHarem.h"

VirtualHarem::VirtualHarem() {
    this->dataManager = new DataManager(&dataStack);
    this->hiveMind = new HiveMind(dataManager);
}