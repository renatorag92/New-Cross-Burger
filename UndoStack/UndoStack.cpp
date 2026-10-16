#include "UndoStack.hpp"
#include "NoStack.hpp"

using namespace std;

UndoStack::UndoStack() {
    this->top = nullptr;
}

bool UndoStack::isEmpty() const {
    return this->top == nullptr;
}

bool UndoStack::push(const string& action) {
    NoStack * newNode = new NoStack(action);

    newNode->next = this->top;
    this->top = newNode;

    return true;
}

bool UndoStack::pop() {
    if (isEmpty()) {
        return false;
    }
    NoStack * temp = this->top;
    this->top = this->top->next;
    delete temp;

    return true;
}

string UndoStack::consultTop() const {
    if (isEmpty()) {
        return "";
    }
}

UndoStack::~UndoStack() {
    while (!isEmpty()) {
        pop();
    }
}