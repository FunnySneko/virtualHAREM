#include "world.h"

Object* World::CreateObject(DataPiece *thisObject) {
    Object object(thisObject);
    objects.push_back(object);
    return &objects.back();
}