#pragma once
#include <vector>
#include <string>
#include <iostream>

enum class DATA_TYPE {
    PERSON,
    OBJECT,
    LOCATION,
};

class DataPiece {
public:
    void Display(std::string label);
    DataPiece(DATA_TYPE dataType, int numericalData, std::string stringData);
    DATA_TYPE dataType;
    int numericalData;
    std::string stringData;
};

class DataStack {
public:
    DataPiece* AddData(DATA_TYPE dataType, int numericalData, std::string stringData);
private:
    std::vector<DataPiece*> stack;
};

class DataManager {
public:
    DataManager(DataStack* dataStack);
    DataPiece* EmitData(DATA_TYPE dataType, int numericalData, std::string stringData);
    DataPiece* EmitData(DATA_TYPE dataType, int numericalData);
    DataPiece* EmitData(DATA_TYPE dataType, std::string stringData);
private:
    DataStack* dataStack;
};