#include "object.h"

Object::Object(DataPiece *thisObject) {
    this->thisObject = thisObject;
}

void Object::Display() {
    std::cout << "OBJECT: " << dataNames[int(thisObject->dataType)] << std::endl;
    for (Attribute& attribute : attributes.stack) {
        attribute.attribute->Display(attributeNames[int(attribute.type)]);
    }
    std::cout << "----------------------------" << std::endl;
}