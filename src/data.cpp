#include "data.h"

void DataPiece::Display(std::string label) {
    std::cout << label << ": " << numericalData << " " << stringData << std::endl;
}

DataPiece::DataPiece(DATA_TYPE dataType, int numericalData, std::string stringData) {
    this->dataType = dataType;
    this->numericalData = numericalData;
    this->stringData = stringData;
}

DataManager::DataManager(DataStack *dataStack) {
    this->dataStack = dataStack;
}

DataPiece *DataManager::EmitData(DATA_TYPE dataType, int numericalData, std::string stringData) {
    DataPiece dataPiece(dataType, numericalData, stringData);
    return dataStack->AddData(dataPiece);
}

DataPiece *DataManager::EmitData(DATA_TYPE dataType, int numericalData) {
    DataPiece dataPiece(dataType, numericalData, "NO-DATA");
    return dataStack->AddData(dataPiece);
}

DataPiece *DataManager::EmitData(DATA_TYPE dataType, std::string stringData) {
    DataPiece dataPiece(dataType, -1, stringData);
    return dataStack->AddData(dataPiece);
}

DataPiece *DataStack::AddData(DataPiece dataPiece) {
    stack.push_back(dataPiece);
    return &stack.back();
}