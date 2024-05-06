#include <iostream>

class MinStack{
private:
    struct Node {
        int value;
        Node *down;
        Node(int v = 0, Node *d = nullptr) {
            value = v;
            down = d;
        }
    };
    Node * top_p;
    long min;
public:
    MinStack() {
        top_p = nullptr;
        min = 0;
    }

    void push(int val) {
        if (top_p == nullptr) {
            top_p = new Node(0, nullptr);
            min = val;
        } else {
            top_p = new Node(val - min, top_p);
            if (val < min) {
                min = val;
            }
        }
    }

    int top() {
        if (top_p->value >= 0) {
            return min + top_p->value;
        } else {
            return min;
        }
    }

    int getMin() {
        return min;
    }

    void pop() {
        if (top_p->value < 0) {
            min -= top_p->value;
        }
        Node *tmp = top_p;
        top_p = top_p->down;
        delete tmp;
    }
}; 

int main() {
    MinStack* minStack = new MinStack();
    minStack->push(-2);
    minStack->push(0);
    minStack->push(-3);
    std::cout << minStack->getMin();  
    minStack->pop();
    std::cout << minStack->top();      
    minStack->getMin();
}