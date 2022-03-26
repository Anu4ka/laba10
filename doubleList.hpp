#pragma once

class dList{
private:
    class Node{
    public:
        int data;
        Node* prev;
        Node* next;
        Node(int data, Node* next);
    };
    Node* head;
    Node* tail;
    int isize;
public:
    dList();
    dList(dList* dList);

    ~dList();
    void pop_front();
    void clear();

    void Setisize(int isize);

    void push_back(int value);
    void filldList();

    int find(const int key);

    void Print();

    friend int DoSMT(dList& original);
};
