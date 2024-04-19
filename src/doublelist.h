#ifndef LABCOLLECTIONS_DOUBLELIST_H
#define LABCOLLECTIONS_DOUBLELIST_H

#include <future>
#include <memory>
#include <ostream>
#include <stdexcept>

template<class T>
class DoubleLinkedList {
private:
    struct Node {
        T data;
        std::shared_ptr<Node> next;
        std::weak_ptr<Node> previous;
        Node(T value): data{value} {}
    };

    std::shared_ptr<Node> head;
    std::shared_ptr<Node> tail;
    int size;
    void checkIndex(int index) const {
        if(index < 0 || index >= size) throw std::out_of_range("Index out of range");
    }

public:
    DoubleLinkedList<T>(): head{nullptr}, tail{nullptr}, size{0} {}
    DoubleLinkedList<T>(T value): head{std::make_shared<Node>(value)}, tail{head}, size{1} {}

    void insertAtBeginning(T value) {
        std::shared_ptr<Node> newNode = std::make_shared<Node>(value);
        if(!head) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head->previous = newNode;
            head = newNode;
        }
        ++size;
    } 

    void insertAtEnd(T value) {
        std::shared_ptr<Node> newNode = std::make_shared<Node>(value);

        if(!tail) head = tail = newNode;
        else {
            tail->next = newNode;
            newNode->previous = tail;
            tail = newNode;
        }

        ++size;
    }

    void insertAtIndex(T value, int index) {
        if(index == 0) {
            insertAtBeginning(value);
            return;
        }
        else if(index == size) {
            insertAtEnd(value);
            return;
        }

        checkIndex(index);
        std::shared_ptr<Node> newNode = std::make_shared<Node>(value);
        std::shared_ptr<Node> current = head;
        for(int i = 0; i < index - 1; i++) {
           current = current->next; 
        }

        newNode->next = current->next;
        newNode->previous = current;
        current->next->previous = newNode;
        current->next = newNode;
        ++size;
    }
    
    void removeFromBeginning() {
        if(!head) {
            throw std::string{"The list is empty, bummer"};
        }
        else if(head == tail) {
            head = tail = nullptr;
        }
        else {
            head = head->next;
            head->previous.reset();
        }
        --size;
    }

    void removeFromEnd() {
        if(!tail) throw std::string{"The list is empty, bummer"};
        else if(tail == head) {
            head = tail = nullptr;
        }
        else {
            tail = tail->previous.lock();
            tail->next.reset();
        }
        --size;
    }

    void removeAtIndex(int index) {
        if(index == 0) {
            removeFromBeginning();
            return;
        }
        if(index == size - 1) {
            removeFromEnd();
            return;
        }

        checkIndex(index);
        std::shared_ptr<Node> current = head;
        for(int i = 0; i < index; i++) {
            current = current->next;
        }
        current->next->previous = current->previous;
        current->previous.lock()->next = current->next;
        --size;
    }

    bool isEmpty() const {
        if(size == 0) return true;
        return false;
    }

    bool search(T value) const {
        std::shared_ptr<Node> current = head;
        while(current->next) {
            if(current->data == value) return true;

            current = current->next;
        }

        return false;
    }
    
    int getSize() const { return size; }

    T operator[](int index) const {
        std::shared_ptr<Node> current = head;
        for(int i = 0; i < index; i++) {
            current = current->next;
        }

        return current->data;
    }
    
    friend std::ostream &operator<<(std::ostream &os, DoubleLinkedList<T> &obj) {
        os << "List data: ";
        std::shared_ptr<Node> current = obj.head;
        while(current) {
            os << current->data << " ";
            current = current->next;
        }

        os << std::endl;
        return os;
    }
};





#endif