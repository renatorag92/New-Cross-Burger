#ifndef UNDOSTACK_HPP
#define UNDOSTACK_HPP
#include "NoStack.hpp"

#include <iostream>

class UndoStack {

    private:
    NoStack * top;

    public:
    UndoStack();

    bool push(const std::string& action);
    bool pop();
    bool isEmpty() const;
    std::string consultTop() const;

    ~UndoStack();
};

#endif
