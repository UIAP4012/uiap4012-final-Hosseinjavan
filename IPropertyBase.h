#pragma once
#include <string>

using namespace std;

class IPropertyBase {
public:
    virtual int getId() const = 0;
    virtual const string &getName() const = 0;
    virtual double getCount() const = 0;
    virtual double getPrice() const = 0;
    virtual void updateCount(double newCount) = 0;
    virtual void print() = 0;
};