#include "person.h"

Person::Person(DataPiece *self) {
    this->self = self;
}

void Person::Display() {
    self->Display("NAME");
}