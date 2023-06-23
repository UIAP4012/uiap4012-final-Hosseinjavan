#pragma once

#include "Menu.h"
#include <iostream>
#include <string>
#include "Property.h"

using namespace std;

void Menu::addNewItem() {
    string name;
    cout << "Enter property name: ";
    cin >> name;
    double count;
    cout << "Enter property count: ";
    cin >> count;
    double price;
    cout << "Enter property price: ";
    cin >> price;
    auto item = m_propertyManagement->addNewItem(name, count, price);
    if(item != nullptr){
        cout << "Item added successfully added" << endl;
    }
    m_receiptHandler->writeStocks(item);
}

Menu::Menu(std::shared_ptr<PropertyManagement> propertyManagement, std::shared_ptr<ReceiptHandler> receiptHandler)
    : m_propertyManagement(propertyManagement)
    , m_receiptHandler(receiptHandler)
{

}

void Menu::deleteItem()
{
    if(m_propertyManagement->isItemsEmpty())
    {
        cout << "There are no items to delete" << endl;
        return;
    }
    m_propertyManagement->printItems();
    cout << "Enter Id of item that you want to delete: ";
    int id;
    cin >> id;
    if(m_propertyManagement->deleteItem(id)) {
        cout << "Item with entered id removed successfully" << endl;
    }
    else {
        cout << "Item with entered id not found" << endl;
    }
}

void Menu::updateProperty() {
    if(m_propertyManagement->isItemsEmpty())
    {
        cout << "There are no items to update" << endl;
        return;
    }
    m_propertyManagement->printItems();
    cout << "Enter Id of item that you want to update its count: ";
    int id;
    cin >> id;
    cout << "Enter new count: ";
    double count;
    cin >> count;
    if(m_propertyManagement->updateProperty(id, count)){
        cout << "Count updated successfully" << endl;
    }
    else {
        cout << "Count didn't update successfully due to wrong id or negative count" << endl;
    }
}

void Menu::mainMenu(int userIndex) {
    User user = m_users[userIndex];
    while(true){
        cout << "1-Add new item" << endl;
        cout << "2-Update an item" << endl;
        cout << "3-Delete an item" << endl;
        cout << "4-Buy and item" << endl;
        cout << "5-List items" << endl;
        cout << "6-Exit" << endl;
        cout << "Enter your choice: ";
        int opt;
        cin >> opt;
        if(opt == 6){
            break;
        }
        if(opt == 1){
            addNewItem();
        }
        if(opt == 2){
            updateProperty();
        }
        if(opt == 3){
            deleteItem();
        }
        if(opt == 4){
            buyItem(user);
        }
        if(opt == 5){
            m_propertyManagement->printItems();
        }
    }
}

void Menu::buyItem(User user) {
    if(m_propertyManagement->isItemsEmpty())
    {
        cout << "There are no items to buy " << endl;
        return;
    }
    vector<shared_ptr<IPropertyBase>> boughtItems;
    while(true){
        cout << "1-buy" << endl;
        cout << "2-checkout" << endl;
        cout << "Enter your choice: ";
        int opt;
        cin >> opt;
        if(opt == 1){
            m_propertyManagement->printItems();
            cout << "Enter your choice: ";
            int itemIndex;
            cin >> itemIndex;
            cout << "Enter count of item that you want to buy: ";
            int count;
            cin >> count;
            auto item = m_propertyManagement->buyItem(itemIndex, count);
            if(item != nullptr){
                cout << "item bought successfully" << endl;
                boughtItems.push_back(make_shared<Property>(itemIndex, item->getName(), item->getCount(), item->getCount()));
            }
            else {
                cout << "item index is wrong or count is more than stock" << endl;
            }
        }
        if(opt == 2){
            m_receiptHandler->writeReceipt(user, boughtItems);
            break;
        }
    }
}

void Menu::loginMenu() {
    while(true){
        cout << "1-Sign Up" << endl;
        cout << "2-Login" << endl;
        cout << "3-Exit" << endl;
        cout << "Enter your choice: ";
        int opt;
        cin >> opt;
        if(opt == 1){
            int userIndex = signup();
            if(userIndex != -1){
                cout << "you signed up" << endl;
                mainMenu(userIndex);
            }
            else{
                cout << "username is already exist" << endl;
            }
        }
        if(opt == 2){
            int userIndex = login();
            if(userIndex != -1){
                mainMenu(userIndex);
            }
            else{
                cout << "user name or password is invalid" << endl;
            }
        }
        if(opt == 3){
            break;
        }
    }
}

int Menu::login() {
    cout << "Enter username: ";
    string username;
    cin >> username;
    cout << "Enter password: ";
    string password;
    cin >> password;
    for(int i = 0; i < m_users.size(); i++){
        if(m_users[i].login(username, password)){
            return i;
        }
    }
    return -1;
}

int Menu::signup() {
    cout << "Enter name: ";
    string name;
    cin >> name;
    cout << "Enter last name: ";
    string lastName;
    cin >> lastName;
    cout << "Enter username: ";
    string username;
    cin >> username;
    cout << "enter password: ";
    string password;
    cin >> password;
    if(!checkIsUsernameAvailable(username))
    {
        return -1;
    }
    m_users.push_back(User(name, lastName, m_userCountAsId++, username, password));
    return m_users.size() - 1;
}

bool Menu::checkIsUsernameAvailable(string username) {
    for(int i = 0; i < m_users.size(); i++){
        if(m_users[i].getUsername() == username){
            return false;
        }
    }
    return true;
}
