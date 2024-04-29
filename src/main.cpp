#include <iostream>
#include "queue.h"
#include "linkedlist.h"
#include "doublelist.h"
using namespace std;


void testList1() {
    LinkedList<int> list1;
    LinkedList<string> list2{"abc"};

    cout << "List sizes:" << endl;
    cout << list1.getSize() << endl
        << list2.getSize() << endl;

    cout << list2[0] << endl;
    cout << list1.isEmpty() << endl;
    list1.insertAtBeginning(10);
    list2.insertAtEnd("bcd");
    cout << list1[0] << endl;
    list1.insertAtIndex(5, 1);
    list2.insertAtIndex("minecraft", 1);
    cout << list1  << list2;

    list1.removeFromEnd();
    list2.removeFromBeginning();
    
    cout << list1 << list2;
    cout << list1.search(10) << endl
        << list2.search("abc") << endl;
    
    list1.insertAtEnd(4);
    list1.insertAtEnd(43);
    list1.insertAtBeginning(3);
    cout << list1;
    list1.removeAtIndex(2); 
    cout << list1;
}

void testList2() {
    DoubleLinkedList<int> list1;
    DoubleLinkedList<string> list2{"abcd"};
   
    cout << "List sizes:" << endl;
    cout << list1.getSize() << endl
        << list2.getSize() << endl;

    cout << list2[0] << endl;
    cout << list1.isEmpty() << endl;
    list1.insertAtBeginning(10);
    list2.insertAtEnd("bcd");
    cout << list1[0] << endl;
    list1.insertAtIndex(5, 1);
    list2.insertAtIndex("minecraft", 1);
    cout << list1  << list2;

    list1.removeFromEnd();
    list2.removeFromBeginning();
    
    cout << list1 << list2;
    cout << list1.search(10) << endl
        << list2.search("abc") << endl;
    
    list1.insertAtEnd(4);
    list1.insertAtEnd(43);
    list1.insertAtBeginning(3);
    cout << list1;
    list1.removeAtIndex(2); 
    cout << list1;
}

void testQueue() {
   QueueArray<int> queue(5);
   queue.enqueue(5);
   queue.enqueue(10);
   cout << queue.dequeue() << endl;
   cout << queue.peek() << endl;
   cout << queue.isEmpty() << endl;
   while(!queue.isFull()) queue.enqueue(25);
   cout << queue.isFull() << endl;
   while(!queue.isEmpty()) cout << queue.dequeue() << " ";
   cout << endl << queue.isEmpty() << endl;
}

int main(int argc, char *argv[])
{
    cout << "Single linked list: " << endl;
    testList1();
    cout << endl << "Double linked list: " << endl;
    testList2();
    cout << endl << "Queue with array: " << endl; 
    testQueue();
}
