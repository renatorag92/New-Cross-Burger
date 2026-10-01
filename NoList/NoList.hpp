#include <iostream>
#include "Order.hpp"

struct NoList {
    Order data;
    NoList * next;
    NoList * prev;

    // construtor
    NoList(Order order) : data(order), next(nullptr), prev(nullptr) {}
};