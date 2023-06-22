#include "Property.h"

#include <utility>

int Property::getId() const {
    return m_id;
}

const string &Property::getName() const {
    return m_name;
}

double Property::getCount() const {
    return m_count;
}

double Property::getPrice() const {
    return m_price;
}

Property::Property(const int &id, string name, const double &count, const double &price)
    : m_id(id)
    , m_name(std::move(name))
    , m_count(count)
    , m_price(price)
{

}
