#include "Order.hpp"

using namespace std;

Order::Order(int number, string client, string * items, int numItems, float totalValue) {
    this->number = number;
    this->client = client;
    this->numItems = numItems;
    this->totalValue = totalValue;

    // Alocação dinâmica do vetor de itens
    this->items = new string[numItems];
    
    for (int i = 0; i < numItems; i++) {
        this->items[i] = items[i];
    }

    Order::~Order();
}

int Order::getNumber() const {
    return this->number;
}

string Order::getClient() const {
    return this->client;
}

string * Order::getItems() const {
    return this->items;
}

int Order::getNumItems() {
    return this->numItems;
}

float Order::getTotalValue() const {
    return this->totalValue;
}
