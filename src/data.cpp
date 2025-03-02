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
    return dataStack->AddData(dataType, numericalData, stringData);
}

DataPiece *DataManager::EmitData(DATA_TYPE dataType, int numericalData) {
    return dataStack->AddData(dataType, numericalData, "NO-DATA");
}

DataPiece *DataManager::EmitData(DATA_TYPE dataType, std::string stringData) {
    return dataStack->AddData(dataType, -1, stringData);
}

DataPiece *DataStack::AddData(DATA_TYPE dataType, int numericalData, std::string stringData) {
    DataPiece* dataPiece = new DataPiece(dataType, numericalData, stringData);
    stack.push_back(dataPiece);
    return stack.back();
}