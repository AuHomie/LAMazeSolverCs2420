#ifndef Queue_H
#define Queue_H
#include <iostream>
#include <string>
#include <cstdio>
#include <sstream>

template <typename Type>
class Queue{
private:
    struct Node {
        Type data;
        Node* next;
        Node(Type val) : data(val), next(nullptr) {}
    };

    Node* front;
    Node* back;
    int size;

    // Private recursive function for operator<<
    std::string recursive_str(Node* curr) {
        if (!curr) return "";
        return std::to_string(curr->data) + (curr->next ? "->" + recursive_str(curr->next) : "");
    }

/*
Queue(): Constructor, sets the front and back pointer to nullptr and initializes any other additional variables
Queue(const Queue &other):  Copy Constructor, creates a deep copy of the other stack
~Queue(); Deallocates memory by deleting all the existing nodes in the Queue
void enqueue(Type item); Adds an item to the end of the queue
void dequeue(); removes an item from the front of the queue
Type peek(); returns the value of the item at the front of the queue, but does not remove it
int size(); returns the number of items in the queue
bool empty(); returns true if the queue is empty
void clear(); deletes the items in the list and sets the size to 0 (don't forget to delete each node using the "delete" command.
friend ostream &operator<< <>(ostream &out, Queue<Type> &q); Allows the user to output the queue formatted as... item1->item2->item3->item4.  For example, if the queue has values 1, 2, 3, 4 with 1 at the front and 4 at the end it would return 1->2->3->4  It is recommended that you use recursion to accomplish this function.  You may use a private recursive to code the logic, then the operator would just return the results of the recursive function  such as...  string recursive_str(Node<Type> *curr);
One possible Pseudocode solution is as follows...

If the current pointer's next value is null
     return the data of the current node
Else
     return the data of the current node then a "->" then the results of the recursive call

*/


};
#endif // Queue_H