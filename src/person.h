#pragma once
#include "data.h"
#include "vector"

class Connection {
public:
    int strength;
    DataPiece* data1;
    DataPiece* data2;    
};

class Person {
public:
    Person(DataPiece* self);
    void Display();
    DataPiece* self;
};