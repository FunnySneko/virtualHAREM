#pragma once
#include "hiveMind.h"

class VirtualHarem {
public:
    VirtualHarem();
    DataStack dataStack;
    DataManager* dataManager;
    HiveMind* hiveMind;
};