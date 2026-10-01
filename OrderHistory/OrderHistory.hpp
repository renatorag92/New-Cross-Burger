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
    Order insert(Order order);
    int removeByNumber(int number);
    int search(int number);
    void printHistory();
};

#endif