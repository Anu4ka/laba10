#include <iostream>
#include <exception>

#include "List.hpp"

using namespace std;

List::Node::Node(char data, Node* p = nullptr){
    this->data = data;
    this->p = p;
}

List::List(){
    isize = 0;
    head = nullptr;
}

List::List(char data){
    this->data = data;
    isize = 0;
    head = nullptr;
}

void List::clear(){
    while(isize){
        this->pop_front();
    }
}

List::~List(){
    this->clear();
}

List::List(List* other){
    Node* it = other->head;
    while(it != nullptr){
        this->push_back(it->data);
        it = it->p;
    }
}

int List::GetSize(){
    return isize;
}

void List::push_back(char data){
    if(head == nullptr){
        head = new Node(data);
    } else {
        Node* current = this->head;
        while(current->p != nullptr){
            current = current->p;
        }
        current->p = new Node(data);
    }
    isize++;
}

void List::pop_front(){
    Node* temp = head;
    head = head->p;
    delete temp;
    isize--;
}

void List::Print(){
    while(head != nullptr){
        cout << head->data << " ";
        head = head->p;
    }
}

bool List::find(const char key){
    Node* temp = head;
    while(head != nullptr){
        if(head->data == key){
            head = temp;
            return true;
        }
        head = head->p;
    }
    head = temp;
    return false;
}

void List::GetUnicElements(List* other, List* newList){
    while(head != nullptr){
        char temp = head->data;
        bool signOther = other->find(temp);
        bool signNew = newList->find(temp);
        if(!signOther && !signNew){
            newList->push_back(temp);
        }
        head = head->p;
    }
}