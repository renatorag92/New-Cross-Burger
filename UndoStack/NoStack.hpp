#ifndef NOSTACK_HPP
#define NOSTACK_HPP
#include <iostream>

#include <string>

struct NoStack {
    std::string action;
    NoStack * next;

    // construtor
    NoStack(std::string act) : action(act), next(nullptr) {}
};

#endif