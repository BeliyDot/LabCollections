#ifndef LABCOLLECTIONS_QUEUE_H
#define LABCOLLECTIONS_QUEUE_H

#include <stdexcept>
template <class T>
class QueueArray { 
private:
    T *arr;
    int size;
    int front;
    int rear;
public:
    QueueArray<T>(int newSize): size{newSize}, front{0}, rear{0} {
        arr = new T[newSize];
    }

    void enqueue(T value) {
       if(rear == size) throw std::string{"The queue is full!"};

       arr[rear] = value; 
       rear++;
    }

    T dequeue() {
        if(front == rear) throw std::string{"The queue is empty!"};

        T value = arr[front];
        front++;
        if(front == rear) {
            front = 0;
            rear = 0;
        }
        
        return value;
    }
    
    T peek() {
        if(front == rear) throw std::string{"The queue is empty!"};
        
        return arr[front];
    }
    
    bool isEmpty() const {
        if(front == rear) return true;
        else return false;
    }

    bool isFull() const {
        if(rear == size) return true;
        else return false;
    }

    ~QueueArray<T>() {
        delete arr;
    }
};

#endif