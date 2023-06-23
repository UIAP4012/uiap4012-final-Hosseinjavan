#pragma once
#include "Person.h"

class User : public Person{
    string m_username;
    string m_password;
    int m_passwordHash;
public:
    User(string name, string lastName, int id, string username, string password);
    const string &getUsername() const;
    bool login(string username, string password);
    int getPasswordHash();
};