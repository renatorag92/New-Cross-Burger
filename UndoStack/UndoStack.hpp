#ifndef UNDOSTACK_HPP
#define UNDOSTACK_HPP
#include "NoStack.hpp"

#include <iostream>

class UndoStack {

    private:
    NoStack * top;

    public:
    UndoStack();

    std::string push() const;
    void pop() const;
    bool isEmpty() const;
    std::string consultTop() const;

    ~UndoStack();
};

#endif
