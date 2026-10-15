#include "OrderHistory.hpp"
#include "NoList.hpp"

using namespace std;

OrderHistory::OrderHistory() {
    this->first = nullptr;
    this->last = nullptr;
}

bool OrderHistory::insertEnd(const Order &order) {
    NoList *newNode = new NoList(order);

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

bool OrderHistory::insertFront(const Order &order) {
    NoList *newNode = new NoList(order);

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

bool OrderHistory::insertAt(const Order &order, const int position) {
    if (position < 0) {
        return false;
    }

    if (position == 0) {
        return insertFront(order);
    }

    NoList * before = this->first;
    int index = 0;
    while (before != nullptr && index < (position - 1)) {
        before  = before->next;
        index++;
    }
    
    if (before == nullptr) {
        return false;
    }

    if (before->next == nullptr) {
        return insertEnd(order);
    }

    NoList * newNode = new NoList(order);
    NoList * nextNode = before->next;

    newNode->prev = before;
    newNode->next = nextNode;
    before->next = newNode;
    nextNode->prev = newNode;

    return true;
}

Order *OrderHistory::consultFirst() const {
    if (this->first == nullptr) {
        return nullptr;
    }
    else {
       return &(this->first->data) ;
    }
}

Order *OrderHistory::consultLast() const {
    if (this->first == nullptr) {
        return nullptr;
    }
    else {
        return &(this->last->data);
    } 
}

Order *OrderHistory::searchByNumber(const int number) const {
    NoList * current = this->first;

    while (current != nullptr) {
        if (current->data.getNumber() == number) {
            return &(current->data);
        }
        current = current->next;
    }
    return nullptr;
}

bool OrderHistory::removeOrder(const int number) {
    for (NoList * current = this->first; current != nullptr; current = current->next) {
        if (current->data.getNumber() == number) {
            if (current->prev != nullptr) {
                current->prev->next = current->next;
            }
            else {
                this->first = current->next;
            }

            if (current->next != nullptr) {
                current->next->prev = current->prev;
            }
            else {
                this->last = current->prev;
            }
            delete current;
            return true;
        }
    }
    return false;
}

void OrderHistory::printHistory() const {
    if (this->first == nullptr) {
        cout << "Historico vazio." << endl;
        return;
    }

    NoList * current = this->first;

    while (current != nullptr) {
        cout << "Pedido: " << current->data.getNumber()
        << "-" << current->data.getClient()
        << "R$ " << current->data.getTotalValue() << endl;

        current = current->next;
    }
}

OrderHistory::~OrderHistory() {
    NoList * current = this->first;

    while (current != nullptr) {
        NoList * nextNode = current->next;
        delete current;
        current = nextNode;        
    }

    this->first = nullptr;
    this->last= nullptr;

}



