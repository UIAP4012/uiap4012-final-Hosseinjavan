#pragma once
#include <string>

using namespace std;

class Property {
    int m_id;
    string m_name;
    double m_count;
    double m_price;
public:
    Property(int id, string name, double count, double price);
    int getMId() const;
    const string &getMName() const;
    double getMCount() const;
    double getMPrice() const;
};