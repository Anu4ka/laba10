#pragma once

class List{
private:
    class Node{
    public:
        char data;
        Node* p;
        Node(char data, Node* p);
    };
    Node* head;
    int isize;
public:
    List();
    List(char data);
    List(List* other);

    ~List();
    void pop_front();
    void clear();

    int GetSize();
    bool find(const char key);

    void push_back(char data);
    
    void Print();

    void GetUnicElements(List* other, List* newList);
};