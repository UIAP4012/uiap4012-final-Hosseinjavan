#include "PropertyManagement.h"
#include <iostream>
using namespace std;

std::shared_ptr<Property> PropertyManagement::addNewItem(string name, double count, double price)
{
    auto item = std::make_shared<Property>(m_itemCounterAsId, name, count, price);
    m_properties.push_back(item);
    m_itemCounterAsId++;
    return item;
}

PropertyManagement::PropertyManagement()
    : m_itemCounterAsId(0)
{

}

bool PropertyManagement::deleteItem(int id)
{
    for(auto it = m_properties.begin(); it != m_properties.end(); it++){
        if(it->get()->getId() == id){
            m_properties.erase(it);
            return true;
        }
    }
    return false;
}

void PropertyManagement::printItems()
{
    for(auto it = m_properties.begin(); it != m_properties.end(); it++)
    {
        it->get()->print();
    }
}

bool PropertyManagement::updateProperty(int id, double newCount) {
    if(newCount < 0)
    {
        return false;
    }
    for(int i = 0; i < m_properties.size(); i++)
    {
        if(m_properties[i]->getId() == id){
            if(m_properties[i]->getCount() >= newCount) {
                m_properties[i]->updateCount(newCount);
                return true;
            }
        }
    }
    return false;
}

shared_ptr<IPropertyBase> PropertyManagement::buyItem(int id, double count) {
    for(int i = 0; i < m_properties.size(); i++){
        if(m_properties[i]->getId() == id) {
            if (m_properties[i]->getCount() >= count) {
                m_properties[i]->updateCount(m_properties[i]->getCount() - count);
                cout << "item found to buy" << endl;
                return m_properties[i];
            }
        }
    }
    return nullptr;
}

bool PropertyManagement::isItemsEmpty() {
    return m_properties.empty();
}
