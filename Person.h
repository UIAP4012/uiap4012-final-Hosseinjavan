#pragma once
#include <string>

using namespace std;

class Person {
    string m_name;
    string m_lastName;
    int m_id;
public:
    Person(string name, string lastName, int id);
    const string &getName() const;
    const string &getLastName() const;
    int getId() const;
};