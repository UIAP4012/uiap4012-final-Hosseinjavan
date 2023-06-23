#include "Person.h"

Person::Person(string name, string lastName, int id)
    : m_name(name)
    , m_lastName(lastName)
    , m_id(id)
{

}

const string &Person::getName() const {
    return m_name;
}

const string &Person::getLastName() const {
    return m_lastName;
}

int Person::getId() const {
    return m_id;
}
