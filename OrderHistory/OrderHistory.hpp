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
    bool insertFront(const Order& order);
    bool insertAt(const Order& order, const int position);


    Order * consultFirst() const;
    Order * consultLast() const;

    Order * searchByNumber(const int number) const;
    bool removeOrder(const int number);
    
    void printHistory() const;

    ~OrderHistory();
};

#endif