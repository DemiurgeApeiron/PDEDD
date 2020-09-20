#include <iostream>
using namespace std;
#pragma once
template <class T>
class DataBase
{
private:

public:
    DataBase()=default;
    ~DataBase();
    virtual T display();
};

