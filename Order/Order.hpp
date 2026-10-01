#ifndef ORDER_HPP
#define ORDER_HPP

#include <iostream>

class Order {
    private:
    int number;
    std::string client;
    std::string * items;
    int numItems;
    int sizeItems;
    float totalValue;

    public:
    Order(int number, std::string client, std::string * items, int numItems, float totalValue);
    int getNumber() const;
    std::string getClient() const;
    std::string * getItems() const;
    int getNumItems();
    float getTotalValue() const;

    ~Order();
};

#endif