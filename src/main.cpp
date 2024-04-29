#include <iostream>
#include "linkedlist.h"
#include "doublelist.h"
#include "priorityQueue.h"
#include "queue.h"
#include "stack.h"
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
    QueueLinkedList<char> quetie;
    
    cout << "Array: " << endl;

    queue.enqueue(5);
    queue.enqueue(10);
    cout << queue.dequeue() << endl;
    cout << queue.peek() << endl;
    
    while(!queue.isFull()) queue.enqueue(23);
    cout << queue.isFull() << endl;

    while(!queue.isEmpty()) cout << queue.dequeue() << endl;
    cout << queue.isEmpty() << endl;
    
    cout << "Linked list: " << endl;
    
    quetie.enqueue('w');
    quetie.enqueue('5');

    cout << quetie.peek() << endl;
    quetie.enqueue('4');
    while(!quetie.isEmpty()) cout << quetie.dequeue() << endl;
    cout << quetie.isEmpty() << endl;
}

void testPriorityQueue() {
    AscendingPriorityQueue<int> aQueue(3);
    DescendingPriorityQueue<int> dQueue(3);
    
    aQueue.enqueue(5);
    dQueue.enqueue(5);
    
    aQueue.enqueue(1);
    dQueue.enqueue(1);
    
    cout << aQueue.peek() << endl;
    cout << dQueue.peek() << endl;
    
    while(!aQueue.isEmpty()) {
        cout << aQueue.dequeue() << " ";
    }
    
    cout << endl;

    while(!dQueue.isEmpty()) {
        cout << dQueue.dequeue() << " ";
    }
    
    cout << endl;
}

void testStack() {
    StackArray<int> stack1(5);
    StackList<char> stack2('f');

    stack1.push(3);
    stack2.push('e');

    stack2.push('4');
    stack1.push(228);

    cout << stack1.peek() << endl;
    cout << stack2.peek() << endl;

    while(!stack1.isFull()) stack1.push(21);

    while(!stack1.isEmpty()) cout << stack1.pop() << " ";

    cout << endl;

    while(!stack2.isEmpty()) cout << stack2.pop() << " ";
    
    cout << endl;
}

int main(int argc, char *argv[])
{
    cout << "Single linked list: " << endl;
    testList1();
    cout << endl << "Double linked list: " << endl;
    testList2();
    cout << endl << "Queue: " << endl;
    testQueue();
    cout << endl << "Priority Queue: " << endl;
    testPriorityQueue();
    cout << endl << "Stack: " << endl;
    testStack();
}
