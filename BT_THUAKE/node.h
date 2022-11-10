#ifndef node_h
#define node_h

#include <iostream>
using namespace std;

class Node
{
    private:
        int data;
        Node *next;
    public:
        Node(int = 0);
        void conNode(Node *);
        int& getData();
        void setData(int);
        Node* nextNode();
};

Node::Node(int val) {
    data = val;
    next = NULL;
}

void Node::conNode(Node *nn) {
    next = nn;
}

int& Node::getData() {
    return data;
}

void Node::setData(int val) {
    data = val;
}

Node* Node::nextNode() {
    return next;
}

#endif