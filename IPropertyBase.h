#pragma once
#include <string>

using namespace std;

class IPropertyBase {
    virtual int getId() const = 0;
    virtual const string &getName() const = 0;
    virtual double getCount() const = 0;
    virtual double getPrice() const = 0;
};