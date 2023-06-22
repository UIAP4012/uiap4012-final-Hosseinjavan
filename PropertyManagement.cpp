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
    m_properties[m_itemCounterAsId] = std::make_shared<Property>(m_itemCounterAsId++, name, count, price);
    cout << m_properties.size();
    return true;
}

PropertyManagement::PropertyManagement()
    : m_itemCounterAsId(0)
{

}
