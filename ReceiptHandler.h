#pragma once
#include "IPropertyBase.h"
#include "User.h"
#include <memory>
#include <vector>

class ReceiptHandler {
    string m_stocksPath;
public:
    ReceiptHandler();
    void writeReceipt(User user, std::vector<std::shared_ptr<IPropertyBase>> items);
    void writeStocks(std::shared_ptr<IPropertyBase> item);
};