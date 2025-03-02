#pragma once
#include "data.h"

class Object {
public:
    Object(DataPiece* thisObject);
    DataPiece* thisObject;
    AttributeStack attributes;
};