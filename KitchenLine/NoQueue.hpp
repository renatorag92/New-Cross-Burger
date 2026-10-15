#include <iostream>
#include "Order.hpp"

struct NoQueue {
    Order data;
    NoQueue * next;

    // construtor
    NoQueue(Order order) : data(order), next(nullptr) {}
};

