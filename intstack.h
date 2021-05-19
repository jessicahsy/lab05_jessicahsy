// intstack.h - stack class for CS 24 lab practice

// The class is implemented here too. All very bare bones,
// with no error-checking nor even pre-condition stating.
// But know two things: (1) don't push on full stack, which
// is a stack currently holding 10 ints; (2) don't pop or
// top from empty stack - use bool empty() to check.

#ifndef INTSTACK_H
#define INTSTACK_H

#define CAPACITY 10
#include <iostream>
#include <typeinfo>
class Stack {

public:
    Stack() : next(0) { }
    void push(int n) {
        if (next>=10){std::cout<<"Stack Overflow\n";
        }else{data[next++] = n;}
    }
    void pop() {
        if(next<=0){std::cout<<"Stack Underflow\n";
        }else{--next;}
    }
    int top() const { return data[next-1]; }
    bool empty() const { return next <= 0; }
    int size() {
        return next;
    }
    bool full() const{return next==10;}
    void get_next() const {std::cout<<next<<std::endl;}
private:
    int next, data[CAPACITY];
};

#endif
