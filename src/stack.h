#ifndef LABCOLLECTIONS_STACK_H
#define LABCOLLECTIONS_STACK_H

#include "linkedlist.h"
#include <stdexcept>
template<class T>
class StackArray {
private:
    T *arr;
    int size;
    int index = -1;
public:
    StackArray<T>(int newSize): size{newSize} {
        arr = new T[newSize];
    }
    
    void push(T value) {
        if(index == size - 1) throw std::string{"The stack is full!"}; 

        index++;
        arr[index] = value;
    }
    
    T pop() {
        if(index == -1) throw std::string{"The stack is empty!"};
        
        T value = arr[index];
        index--;

        return value;
    }
    
    T peek() {
        if(index == -1) throw std::string{"The stack is empty!"};
        
        return arr[index];
    }
    
    bool isEmpty() const { return index == -1; }
    bool isFull() const { return index == size - 1; }
};

template<class T>
class StackList {
private:
    LinkedList<T> list;
public:
    StackList<T>(): list{LinkedList<T>()} {}
    StackList<T>(T value): list{LinkedList<T>(value)} {}
    
    void push(T value) {
        list.insertAtEnd(value);
    }
    
    T pop() {
        if(list.isEmpty()) throw std::string{"The stack is empty!"};

        T value = list[list.getSize() - 1];
        list.removeFromEnd();
        return value;
    }
    
    T peek() {
        if(list.isEmpty()) throw std::string{"The stack is empty!"};
        
        return list[list.getSize() - 1];
    }
    
    bool isEmpty() const { return list.isEmpty(); }
};
#endif