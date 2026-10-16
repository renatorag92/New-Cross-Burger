#include "KitchenLine.hpp"
#include "NoQueue.hpp"

using namespace std;

KitchenLine::KitchenLine() {
    this->front = nullptr;
    this->rear = nullptr;
}

bool KitchenLine::isEmpty() {
    return this->front == nullptr;
}

bool KitchenLine::enqueue(const Order& order) {
    NoQueue * newNode = new NoQueue(order);

    if (this->isEmpty()) {
        this->front = newNode;
        this->rear = newNode;
    }
    else {    
        this->rear->next = newNode;
        this->rear = newNode;
    }
    return true;
}

bool KitchenLine::dequeue() {
    if (this->isEmpty()) {
        return false;
    }
    NoQueue * temp = this->front;
    this->front = this->front->next;
    delete temp;
               
    if (this->front == nullptr) {
        this->rear = nullptr; 
    }
    return true;  
}

Order * KitchenLine::consultFirst() const {
    if (this->front == nullptr) {
        return nullptr;    
    }
    else {
        return &(this->front->data);
    }
}

KitchenLine::~KitchenLine() {
    while (!isEmpty()) {
        dequeue();
    }
}