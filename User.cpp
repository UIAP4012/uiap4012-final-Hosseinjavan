#include "User.h"
#include <unordered_map>

User::User(string name, string lastName, int id, string username, string password)
    : Person(name, lastName, id)
    , m_username(username)
    , m_password(password)
{
    hash<string> hasher;
    m_passwordHash = hasher(password);
}

const string &User::getUsername() const {
    return m_username;
}

bool User::login(string username, string password) {
    return m_username == username && m_password == password;
}

int User::getPasswordHash() {
    return m_passwordHash;
}
