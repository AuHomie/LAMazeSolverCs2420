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
    int count;

    // Private recursive function for operator<<
    std::string recursive_str(Node* curr) {
        if (!curr) return "";
        return std::to_string(curr->data) + (curr->next ? "->" + recursive_str(curr->next) : "");
    }
public:
    Queue() : front(nullptr), back(nullptr), count(0) {};

    Queue(const Queue &other) : front(nullptr), back(nullptr), count(0){
        Node* curr = other.front;
        while ((curr != nullptr))
        {
            enqueue(curr->data);
            curr = curr->next;
        }
    }

    ~Queue(){ 
        clear();
    }  

    void enqueue(Type item) {
        Node* newNode = new Node(item);
        if (back) {
            back->next = newNode;
        } else {
            front = newNode;
        }
        back = newNode;
        count++;
    }

    void dequeue(){
        if (front) {
            Node* temp = front;
            front = front->next;
            delete temp;
            count--;
            if (count == 0) {
                back = nullptr;
            }
        }
    }

    Type peek() const {
        if (front) {
            return front->data;
        }
        throw std::runtime_error("Queue is empty");
    }

    int size() const {
        return count;
    }

    bool empty() const {
        return count == 0;
    }
    
    void clear() {
        while (front) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
        back = nullptr;
        size = 0;
    }

    std::string recursive_str(Node* curr) const {
        std::ostringstream oss;
        oss << curr->data;
        return oss.str() + (curr->next ? "->" + recursive_str(curr->next) : "");
    }

    friend std::ostream &operator<<(std::ostream &out, const Queue<Type> &q) {
        if (q.empty()) {
            out << "Queue is empty";
        } else {
            out << q.recursive_str(q.front);
        }
        return out;
    }        

    Queue& operator=(const Queue &other) {
        if (this != &other) {
            clear(); // Clear current queue
            Node* curr = other.front;
            while (curr) {
                enqueue(curr->data);
                curr = curr->next;
            }
        }
        return *this;
    }           

};
#endif // Queue_H