#ifndef STACK_H
#define STACK_H

#include "DoublyLinkedList.h"

template <typename T>
class Stack
{
   private:
    DoublyLinkedList<T> list;

   public:
    Stack() {}

    void push(T& value) { list.push_back(value); }

    void pop() { list.pop_back(); }

    T& top() { return list.back(); }

    bool empty() { return list.empty(); }

    size_t size() { return list.size(); }
};

#endif
