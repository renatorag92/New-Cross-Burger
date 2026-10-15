#ifndef KITCHENLINE_HPP
#define KITCHENLINE_HPP
#include "NoQueue.hpp"

#include <iostream>

class KitchenLine {

    private:
    NoQueue * front;
    NoQueue * rear;

    public:
    KitchenLine();

    bool enqueue(const Order& order);
    bool dequeue();
    bool isEmpty();
    Order * consultFirst() const;

    ~KitchenLine();
};

#endif



