#ifndef ORDERHISTORY_HPP
#define ORDERHISTORY_HPP 
#include "NoList.hpp"

#include <iostream>

class OrderHistory {
    private:
    NoList * first;
    NoList * last;

    public:
    OrderHistory();

    bool insertEnd(const Order& order);
    bool insertFirst(const Order& order);

    Order * consultFirst();
    Order * consultLast();

    Order * searchByNumber(const int number);
    bool removeByValue(const int number);
    
    void printHistory();

    ~OrderHistory();
};

#endif