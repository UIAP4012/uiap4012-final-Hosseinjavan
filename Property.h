#pragma once
#include "IPropertyBase.h"


class Property : public IPropertyBase{
    int m_id;
    std::string m_name;
    double m_count;
    double m_price;

public:
    Property(const int &id, string name, const double &count, const double &price);
    int getId() const override;
    const string &getName() const override;
    double getCount() const override;
    double getPrice() const override;
    void updateCount(double newCount) override ;
    void print() override;
};