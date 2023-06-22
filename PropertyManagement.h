#pragma once
#include <vector>
#include "IPropertyBase.h"
#include <map>

class PropertyManagement {
    std::map<int, std::shared_ptr<IPropertyBase>> m_properties;
    int m_itemCounterAsId;
    void printItems();
public:
    PropertyManagement();
    bool addNewItem();
    bool deleteItem();
};
