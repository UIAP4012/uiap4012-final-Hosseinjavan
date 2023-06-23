#include "ReceiptHandler.h"
#include <iostream>
#include <fstream>

void ReceiptHandler::writeReceipt(User user, std::vector<std::shared_ptr<IPropertyBase>> items) {
     std::ofstream receiptFile;
     string path = "../Receipts/";
     //creating this variable for debug
     string finalPath = path.append(user.getUsername()).append(".csv");
     receiptFile.open(finalPath, std::ios_base::out);
     if(!receiptFile.is_open()){
         cout << "file didn't open" << endl;
     }
     receiptFile << "Id,name,count,price\n";
     for(int i = 0; i < items.size(); i++){
         receiptFile << items[i]->getId() << "," << items[i]->getName() << "," << items[i]->getCount() << "," << items[i]->getPrice() << "\n";
     }
     receiptFile.close();
}

void ReceiptHandler::writeStocks(std::shared_ptr<IPropertyBase> item) {
    std::ofstream stocks;
    stocks.open(m_stocksPath, std::ios_base::app);
    stocks << "Id,name,count,price\n";
    stocks << item->getId() << "," << item->getName() << "," << item->getCount() << "," << item->getPrice() << "\n";
    stocks.close();
}

ReceiptHandler::ReceiptHandler()
    : m_stocksPath("../Stocks/Stocks.csv")
{

}
