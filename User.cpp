#include "User.h"

User::User(string name, string lastName, int id, string username, string password)
    : Person(name, lastName, id)
    , m_username(username)
    , m_password(password)
{

}

const string &User::getUsername() const {
    return m_username;
}

bool User::login(string username, string password) {
    return m_username == username && m_password == password;
}
