#pragma once
#include "IPropertyBase.h"
#include "User.h"
#include <memory>
#include <vector>

class Logger {
    string m_stocksPath;
    string m_userPath;
public:
    Logger();
    void writeReceipt(User user, std::vector<std::shared_ptr<IPropertyBase>> items);
    void writeStocks(std::shared_ptr<IPropertyBase> item);
    void writeUserData(User user);
};