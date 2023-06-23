#include<iostream>
#include "Menu.h"
#include "Logger.h"
#include "Property.h"

using namespace std;

int main(){
    Menu menu(std::make_shared<PropertyManagement>(), std::make_shared<Logger>());
    /*
    Logger receiptHandler;
    vector<shared_ptr<IPropertyBase>> tmp;
    tmp.push_back(make_shared<Property>(0, "Iphone13", 10, 40));
    User user("mostafa", "jalalhoseiny", 0, "mostafajalal20", "123456");
    receiptHandler.writeStocks(tmp[0]);
     */
    menu.loginMenu();
}

