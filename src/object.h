#pragma once
#include "data.h"

class Object {
public:
    Object(DataPiece* thisObject);
    void Display();
    DataPiece* thisObject;
    AttributeStack attributes;
};