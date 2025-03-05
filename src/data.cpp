#include "data.h"

void DataPiece::Display(std::string label) {
    std::cout << label << ": " <<  stringData;
    if (numericalData != -1) {
        std::cout << " " << numericalData;
    }
    std::cout << std::endl;
}

DataPiece::DataPiece(DATA_TYPE dataType, int numericalData, std::string stringData) {
    this->dataType = dataType;
    this->numericalData = numericalData;
    this->stringData = stringData;
}

DataManager::DataManager() {
    CreateStaticData();
}

void DataManager::DisplayData() {
    dataStack.Display();
}

void DataManager::CreateStaticData() {
    fallbackData = EmitData(DATA_TYPE::FALLBACK, "ERROR");
    EmitData(DATA_TYPE::PERSON_ATTRIBUTE, personAttributeNames[int(PERSON_ATTRIBUTE::GENDER_MALE)]);
    EmitData(DATA_TYPE::PERSON_ATTRIBUTE, personAttributeNames[int(PERSON_ATTRIBUTE::GENDER_FEMALE)]);
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

DataPiece *DataManager::GetData(DATA_TYPE dataType, std::string stringData) {
    DataPiece* dataPiece = dataStack.GetData(dataType, stringData);
    if(dataPiece != nullptr) {
        return dataPiece;
    } else {
        return fallbackData;
    }
}

void DataStack::Display() {
    std::cout << "DATA STACK" << std::endl;
    for (DataPiece* dataPiece : stack) {
        dataPiece->Display("DATA_PIECE");
    }
}

DataPiece *DataStack::AddData(DATA_TYPE dataType, int numericalData, std::string stringData) {
    DataPiece* dataPiece = new DataPiece(dataType, numericalData, stringData);
    stack.push_back(dataPiece);
    return stack.back();
}

DataPiece *DataStack::GetData(DATA_TYPE dataType, std::string stringData) {
    for(DataPiece* dataPiece : stack) {
        if(dataPiece->dataType == dataType && dataPiece->stringData == stringData) {
            return dataPiece;
        }
    }
    return nullptr;
}

Attribute *AttributeStack::AddAttribute(ATTRIBUTE_TYPE type, DataPiece *attributeData, bool isObservable) {
    Attribute attribute(type, attributeData, isObservable);
    for (ATTRIBUTE_TYPE& uniqueAttribute : uniqueAttributes) {
        if (type == uniqueAttribute) {
            RemoveAttribute(type);
        }
    }
    stack.push_back(attribute);
    return &stack.back();
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