
#include "Property.h"

Property::Property(int id, string name, double count, double price)
    : m_id(id)
    , m_name(name)
    , m_count(count)
    , m_price(price)
{

}

int Property::getMId() const {
    return m_id;
}

const string &Property::getMName() const {
    return m_name;
}

double Property::getMCount() const {
    return m_count;
}

double Property::getMPrice() const {
    return m_price;
}
