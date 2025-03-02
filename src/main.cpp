#include "virtualHarem.h"

VirtualHarem virtualHarem;

int main() {
    virtualHarem.hiveMind->CreatePerson("TEST_GUY_1");
    virtualHarem.hiveMind->CreatePerson("TEST_GUY_2");
    //virtualHarem.hiveMind->CreatePerson("TEST_GUY_3");
    virtualHarem.hiveMind->Display();
}