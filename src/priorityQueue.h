#ifndef LABCOLLECTIONS_PRIORITYQUEUE_H
#define LABCOLLECTIONS_PRIORITYQUEUE_H

#include "linkedlist.h"
#include <limits.h>

template<class T>
class AscendingPriorityQueue {
private:
    LinkedList<T> list;
    T min;
public:
    AscendingPriorityQueue<T>(): list{LinkedList<T>()} {}
    AscendingPriorityQueue<T>(T value): min{value}, list{LinkedList<T>(value)} {}
    
    void enqueue(T value) {
        if(list.getSize() == 0) min = value;
        else min = min(min, value);
        
        list.insertAtEnd(value);
    }
    
    T dequeue() {
        if(list.isEmpty()) throw std::string{"The queue is empty!"};

        T value = min;
        for(int i = 0; i < list.getSize(); i++) {
            if(list[i] == min) {
                list.removeAtIndex(i);
                break;
            }
        }
        for(int i = 0; i < list.getSize(); i++) {
            min = min(min, value);
        }
        
        return value;
    }
    
    T peek() {
        if(list.isEmpty()) throw std::string{"The queue is empty!"};

        return min;
    }
    
    bool isEmpty() const { return list.isEmpty(); }
     


};

template<class T>
class DescendingPriorityQueue {
private:
    LinkedList<T> list;
    T max;
public:
    DescendingPriorityQueue<T>(): list{LinkedList<T>()} {}
    DescendingPriorityQueue<T>(T value): max{value}, list{LinkedList<T>(value)} {}
    
    void enqueue(T value) {
        if(list.getSize() == 0) max = value;
        else max = max(max, value);
        
        list.insertAtEnd(value);        
    }
    
    T dequeue() {
        if(list.isEmpty()) throw std::string{"The queue is empty!"};

        T value = max;
        for(int i = 0; i < list.getSize(); i++) {
            if(list[i] == max) {
                list.removeAtIndex(i);
                break;
            }
        }
        for(int i = 0; i < list.getSize(); i++) {
            max = max(max, value);
        }
        
        return value;
    }
    
    T peek() {
        if(list.isEmpty()) throw std::string{"The queue is empty!"};

        return max;
    }
    
    bool isEmpty() const { return list.isEmpty(); }
};
#endif