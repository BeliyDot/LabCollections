#ifndef LABCOLLECTIONS_LINKEDLIST_H
#define LABCOLLECTIONS_LINKEDLIST_H

#include <memory>
#include <stdexcept>
#include <utility>
#include <iostream>

template<class T>
class LinkedList {
private:
    struct Node {
        T data;
        std::unique_ptr<Node> next;
        Node(T value): data{value}, next{nullptr} {}
    };

    std::unique_ptr<Node> head;
    int size;
    void checkIndex(int index) {
        if(index < 0 || index >= size) throw std::out_of_range("Index out of range");
    }
public:
    LinkedList<T>(): head{nullptr}, size{0} {}
    LinkedList<T>(T value): head{std::make_unique<Node>(value)}, size{1} {}

    void insertAtBeginning(T value) {
        std::unique_ptr<Node> newNode = std::make_unique<Node>(value);
        newNode->next = std::move(head);

        head = std::move(newNode);
        size++;
    }
    void insertAtEnd(T value) {
        std::unique_ptr<Node> newNode = std::make_unique<Node>(value);
        Node *current = head.get();

        if(!current) {
            head = std::move(newNode);
            size++;
            return;
        }
        while(current->next) {
            current = current->next.get();
        }
        current->next = std::move(newNode);
        size++;
    }
    void removeFromBeginning() {
        if(!head) throw std::out_of_range("The list is empty!");
        head = std::move(head->next);
        size--;
    }
    void removeFromEnd() {
        if(!head) throw std::out_of_range("The list is empty!");
        if(size == 1) {
            head.reset();
            size--;
            return;
        }

        Node *current = head.get();

        while(current->next->next) {
            current = current->next.get();
        }

        current->next.reset();
        size--;
    }
    T operator[](int index) const {
        checkIndex(index);
        Node *current = head.get();
        for(int i = 0; i < index; i++) {
            current = current->next.get();
        }

        return current->data;
    }
    void insertAtIndex(T value, int index) {
        checkIndex(index);
        if(index == 0) {
            insertAtBeginning(value);
            return;
        }
        else if(index == size) {
            insertAtEnd(value);
            return;
        }
        
        std::unique_ptr<Node> newNode = std::make_unique(value);
        Node *current = head.get();

        for(int i = 0; i < index - 1; i++) {
            current = current->next.get();
        }

        newNode->next = std::move(current->next);
        current->next = std::move(newNode);
        size++;
    }
    void removeAtIndex(int index) {
        checkIndex(index);
        if(index == 0) {
            removeFromBeginning();
            return;
        }
        else if(index == size - 1) {
            removeFromEnd();
            return;
        }

        Node *current = head.get();
        for(int i = 0; i < index - 1; i++) {
            current = current->next.get();
        }
        current->next = std::move(current->next->next);
        size--;
    }
    bool isEmpty() {
        if(size == 0) return true;
        else return false;
    }
    
    int getSize() { return size; }

    bool search(T value) {
        Node *current = head.get();

        for(int i = 0; i < size; i++) {
            if(current->data == value) return true;
            else current = current->next.get();
        }

        return false;
    }
    
    friend std::ostream &operator<<(std::ostream &os, LinkedList<T> &obj) {
        Node *current = obj.head.get();
        os << "List data: ";
        while(current != nullptr) {
            os << current->data << " ";
            current = current->next.get();
        }
        os << std::endl;
        return os;
    }
};



#endif