#include "data.h"

void DataPiece::Display(std::string label) {
    std::cout << label << ": " <<  stringData << " " << numericalData << std::endl;
}

DataPiece::DataPiece(DATA_TYPE dataType, int numericalData, std::string stringData) {
    this->dataType = dataType;
    this->numericalData = numericalData;
    this->stringData = stringData;
}

DataPiece *DataManager::EmitData(DATA_TYPE dataType, int numericalData, std::string stringData) {
    return dataStack.AddData(dataType, numericalData, stringData);
}

DataPiece *DataManager::EmitData(DATA_TYPE dataType, int numericalData) {
    return dataStack.AddData(dataType, numericalData, "NO-DATA");
}

DataPiece *DataManager::EmitData(DATA_TYPE dataType, std::string stringData) {
    return dataStack.AddData(dataType, -1, stringData);
}

DataPiece *DataStack::AddData(DATA_TYPE dataType, int numericalData, std::string stringData) {
    DataPiece* dataPiece = new DataPiece(dataType, numericalData, stringData);
    stack.push_back(dataPiece);
    return stack.back();
}

void AttributeStack::AddAttribute(ATTRIBUTE_TYPE type, DataPiece *attributeData, bool isObservable) {
    Attribute attribute(type, attributeData, isObservable);
    for (ATTRIBUTE_TYPE uniqueAttribute : uniqueAttributes) {
        if (type == uniqueAttribute) {
            RemoveAttribute(type);
        }
    }
    stack.push_back(attribute);
}

void AttributeStack::RemoveAttribute(ATTRIBUTE_TYPE type) {
    stack.erase(std::remove_if(stack.begin(), stack.end(), [&](const Attribute& attr) {
        return attr.type == type;
    }), stack.end());
}

Attribute::Attribute(ATTRIBUTE_TYPE type, DataPiece *attribute, bool isObservable) {
    this->type = type;
    this->attribute = attribute;
    this->isObservable = isObservable;
}

DataPiece *DataStackSubjective::AddData(DataPiece *data) {
    stack.push_back(data);
    return stack.back();
}