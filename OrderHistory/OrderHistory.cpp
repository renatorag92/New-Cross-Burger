#include "OrderHistory.hpp"
#include "NoList.hpp"

using namespace std;

OrderHistory::OrderHistory() {
    this->first = nullptr;
    this->last = nullptr;
}

bool OrderHistory::insertEnd(const Order& order) {
    NoList * newNode = new NoList(order);

    if (this->first == nullptr) {
        this->first = newNode;
        this->last = newNode;
    }
    else {
        this->last->next = newNode; 
        newNode->prev = this->last;
        this->last = newNode;
    }
    return true;
}

bool OrderHistory::insertFirst(const Order& order){
    NoList * newNode = new NoList(order);

    if (this->first == nullptr) {
        this->first = newNode;
        this->last = newNode;
    }
    else {
        this->first->prev = newNode;
        newNode->next = this->first;
        this->first = newNode;
    }
    return true;
}








