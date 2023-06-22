#include "PropertyManagement.h"
#include <iostream>
#include "Property.h"
using namespace std;

bool PropertyManagement::addNewItem()
{
    string name;
    cout << "Enter property name: ";
    cin >> name;
    double count;
    cout << "Enter property count: ";
    cin >> count;
    double price;
    cout << "Enter property price: ";
    cin >> price;
    m_properties[m_itemCounterAsId] = std::make_shared<Property>(m_itemCounterAsId, name, count, price);
    m_itemCounterAsId++;
    return true;
}

PropertyManagement::PropertyManagement()
    : m_itemCounterAsId(0)
{

}

bool PropertyManagement::deleteItem()
{
    printItems();
    int id;
    cout << "Enter Id of item that you want to delete: ";
    cin >> id;
    if(m_properties.find(id) != m_properties.end())
    {
        m_properties.erase(id);
        cout << "Item removed successfully" << endl;
        return true;
    }
    cout << "Item with entered id not found";
    return false;
}

void PropertyManagement::printItems()
{
    for(auto it = m_properties.begin(); it != m_properties.end(); it++)
    {
        it->second->print();
    }
}
