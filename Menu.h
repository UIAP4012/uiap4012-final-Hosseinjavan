#pragma once
#include <memory>
#include "PropertyManagement.h"
#include "Logger.h"
#include "User.h"

class Menu {
    std::shared_ptr<PropertyManagement> m_propertyManagement;
    std::shared_ptr<Logger> m_logger;
    vector<User> m_users;
    int m_userCountAsId;

    void addNewItem();
    void deleteItem();
    void updateProperty();
    void buyItem(User user);
    int login();
    int signup();
    bool checkIsUsernameAvailable(string username);
public:
    Menu(std::shared_ptr<PropertyManagement> propertyManagement, std::shared_ptr<Logger> receiptHandler);

    //menu
    void mainMenu(int userIndex);
    void loginMenu();
};