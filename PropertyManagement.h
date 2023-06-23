#pragma once
#include <vector>
#include "IPropertyBase.h"
#include "Property.h"
#include <map>

class PropertyManagement {
    std::vector<std::shared_ptr<IPropertyBase>> m_properties;
    int m_itemCounterAsId;
public:
    PropertyManagement();
    std::shared_ptr<Property> addNewItem(string name, double count, double price);
    bool deleteItem(int id);
    bool updateProperty(int id, double newCount);
    void printItems();
    bool isItemsEmpty();
    std::shared_ptr<IPropertyBase> buyItem(int id, double count);
};
