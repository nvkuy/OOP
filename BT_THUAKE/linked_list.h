#ifndef llist_h
#define llist_h

#include <iostream>
#include "node.h"
using namespace std;

class linked_list
{
    protected:
        int n;
        Node *head;
    public:
        linked_list();
        linked_list(int, const int *);
        linked_list(const linked_list &);
        ~linked_list();
        void ins(int = 0);
        void del(int = 0);
        friend ostream & operator << (ostream &, const linked_list &);
        const linked_list & operator = (const linked_list &);
};

const linked_list & linked_list::operator = (const linked_list & ll) {
    if (this != &ll) {
        n = ll.n;
        Node *cur1, *cur2 = ll.head;
        cur1 = new Node(cur2->getData());
        head = cur1;
        for (int i = 1; i < n; i++) {
            cur2 = cur2->nextNode();
            cur1->conNode(new Node(cur2->getData()));
            cur1 = cur1->nextNode();
        }
    }
    return *this;
}

ostream & operator << (ostream &out, const linked_list &ll) {
    Node *cur = ll.head;
    for (int i = 0; i < ll.n; i++) {
        out << cur->getData() << ' ';
        cur = cur->nextNode();
    }
    return out;
}

linked_list::linked_list(const linked_list & ll) {
    // n = ll.n;
    // Node *cur1, *cur2 = ll.head;
    // cur1 = new Node(cur2->getData());
    // head = cur1;
    // for (int i = 1; i < n; i++) {
    //     cur2 = cur2->nextNode();
    //     cur1->conNode(new Node(cur2->getData()));
    //     cur1 = cur1->nextNode();
    // }
    *this = ll;
}

linked_list::linked_list() {
    n = 0;
    head = NULL;
}

linked_list::linked_list(int n, const int *arr) {
    Node *cur = new Node(arr[0]);
    this->n = n;
    head = cur;
    for (int i = 1; i < n; i++) {
        cur->conNode(new Node(arr[i]));
        cur = cur->nextNode();
    }
}

linked_list::~linked_list() {
    Node *cur = head, *pre;
    while (cur != NULL) {
        pre = cur;
        cur = cur->nextNode();
        delete pre;
    }
}

void linked_list::ins(int val) {
    n++;
    Node *nh = new Node(val);
    nh->conNode(head);
    head = nh;
}

void linked_list::del(int pos) {
    if (pos < 0 || pos >= n)
        return;
    n--;
    if (pos == 0) {
        Node *next_head = head->nextNode();
        delete head;
        head = next_head;
        return;
    }
    Node *cur = head, *pre;
    for (int i = 0; i < pos; i++) {
        pre = cur;
        cur = cur->nextNode();
    }
    pre->conNode(cur->nextNode());
    delete cur;
}


#endif