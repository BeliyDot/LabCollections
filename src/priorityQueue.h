#ifndef LABCOLLECTIONS_PRIORITYQUEUE_H
#define LABCOLLECTIONS_PRIORITYQUEUE_H

#include "linkedlist.h"
#include <limits.h>

template<class T>
class AscendingPriorityQueue {
private:
    LinkedList<T> list;
    T minimum;
public:
    AscendingPriorityQueue<T>(): list{LinkedList<T>()} {}
    AscendingPriorityQueue<T>(T value): minimum{value}, list{LinkedList<T>(value)} {}
    
    void enqueue(T value) {
        if(list.getSize() == 0) minimum = value;
        else minimum = std::min(minimum, value);
        
        list.insertAtEnd(value);        
    }
    
    T dequeue() {
        if(list.isEmpty()) throw std::string{"The queue is empty!"};

        T value = minimum;
        for(int i = 0; i < list.getSize(); i++) {
            if(list[i] == minimum) {
                list.removeAtIndex(i);
                break;
            }
        }
        if(!list.isEmpty()) {
            minimum = list[0];
            for(int i = 1; i < list.getSize(); i++) {
                minimum = std::min(minimum, list[i]);
            }
        }
        
        return value;
    }
    
    T peek() {
        if(list.isEmpty()) throw std::string{"The queue is empty!"};

        return minimum;
    }
    
    bool isEmpty() const { return list.isEmpty(); }
     


};

template<class T>
class DescendingPriorityQueue {
private:
    LinkedList<T> list;
    T maximum;
public:
    DescendingPriorityQueue<T>(): list{LinkedList<T>()} {}
    DescendingPriorityQueue<T>(T value): maximum{value}, list{LinkedList<T>(value)} {}
    
    void enqueue(T value) {
        if(list.getSize() == 0) maximum = value;
        else maximum = std::max(maximum, value);
        
        list.insertAtEnd(value);        
    }
    
    T dequeue() {
        if(list.isEmpty()) throw std::string{"The queue is empty!"};

        T value = maximum;
        for(int i = 0; i < list.getSize(); i++) {
            if(list[i] == maximum) {
                list.removeAtIndex(i);
                break;
            }
        }
        if(!list.isEmpty()) {
            maximum = list[0];
            for(int i = 1; i < list.getSize(); i++) {
                maximum = std::max(maximum, list[i]);
            }
        }
        
        return value;
    }
    
    T peek() {
        if(list.isEmpty()) throw std::string{"The queue is empty!"};

        return maximum;
    }
    
    bool isEmpty() const { return list.isEmpty(); }
};
#endif