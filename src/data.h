#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

enum class DATA_TYPE {
    FALLBACK,
    PERSON,
    PERSON_ATTRIBUTE,
    ITEM,
    LOCATION,
};

static std::vector<std::string> dataNames = {
    "FALLBACK",
    "PERSON_ATTRIBUTE",
    "PERSON",
    "ITEM",
    "LOCATION",
};

enum class ITEM_TYPE {
    SAUSAGE,
    SODA,
    PARACETAMOL,
};

static std::vector<std::string> itemNames = {
    "SAUSAGE",
    "SODA",
    "PARACETAMOL",
};

enum class ATTRIBUTE_TYPE {
    SELF,
    PLACE,
    INHABITANT,
    GENDER,
};

static std::vector<std::string> attributeNames = {
    "SELF",
    "PLACE",
    "INHABITANT",
    "GENDER",
};

enum class PERSON_ATTRIBUTE {
    GENDER_MALE,
    GENDER_FEMALE,
};

static std::vector<std::string> personAttributeNames = {
    "MALE",
    "FEMALE",
};

static std::vector<ATTRIBUTE_TYPE> uniqueAttributes = {
    ATTRIBUTE_TYPE::SELF,
    ATTRIBUTE_TYPE::PLACE,
};

class DataPiece {
public:
    DataPiece(DATA_TYPE dataType, int numericalData, std::string stringData);
    void Display(std::string label);
    DATA_TYPE dataType;
    int numericalData;
    int timesCopied;
    std::string stringData = "NULL";
};

class Attribute {
public:
    Attribute(ATTRIBUTE_TYPE type, DataPiece* attribute, bool isObservable);
    ATTRIBUTE_TYPE type;
    DataPiece* attribute;
    bool isObservable;
};

class DataStack {
public:
    void Display();
    DataPiece* AddData(DATA_TYPE dataType, int numericalData, std::string stringData);
    DataPiece* GetData(DATA_TYPE dataType, std::string stringData);
private:
    std::vector<DataPiece*> stack;
};

class DataStackSubjective {
public:
    DataPiece* AddData(DataPiece* data);
private:
    std::vector<DataPiece*> stack;
};

class AttributeStack {
public:
    Attribute* AddAttribute(ATTRIBUTE_TYPE type, DataPiece* attributeData, bool isObservable);
    void RemoveAttribute(ATTRIBUTE_TYPE type);
    std::vector<Attribute> stack;
};

class DataManagerSubjective {
public:

private:
    DataStackSubjective dataStack;
};

class DataManager {
public:
    DataManager();
    void DisplayData();
    void CreateStaticData();
    DataPiece* EmitData(DATA_TYPE dataType, int numericalData, std::string stringData);
    DataPiece* EmitData(DATA_TYPE dataType, int numericalData);
    DataPiece* EmitData(DATA_TYPE dataType, std::string stringData);
    DataPiece* GetData(DATA_TYPE dataType, std::string stringData);
private:
    DataStack dataStack;
    DataPiece* fallbackData;
};