
#include "doubleList.hpp"
#include <iostream>
#include <exception>

using namespace std;

dList::Node::Node(int data, Node* next = nullptr){
    this->data = data;
    this->next = next;
    this->prev = nullptr;
}

dList::dList(){
    isize = 0;
    head = nullptr;
    tail = nullptr;
}

dList::~dList(){
    this->clear();
}

dList::dList(dList* dList){
    Node* it = dList->head;
    while(it != nullptr){
        this->push_back(it->data);
        it = it->next;
    }
}

void dList::Setisize(int isize){
    this->isize = isize * 2;
}

void dList::pop_front(){
    Node* nexttemp = head;
    head = head->next;
    delete nexttemp;
    isize--;
}

void dList::push_back(int value){
    Node* newNode = new Node(value);
    if(head == nullptr){
        head = newNode;
        tail = newNode;
    } else {
        Node* current = this->head;
        while(current->next != nullptr){
            current = current->next;
        }
        newNode->prev = current;
        current->next = newNode;
        this->tail = newNode;
    }
}

void dList::filldList(){
    for(int i = 0; i < this->isize; i++){
        int value = 0;
        cin >> value;
        this->push_back(value);
    }
}

int dList::find(const int key){
    Node* temp = head;
    int i = 0;
    while(head != nullptr){
        i++;
        if(head->data == key){
            head = temp;
            return i;
        }
        head = head->next;
    }
    head = temp;
    throw runtime_error("There is no element with curtne value in this dList!");
}

void dList::Print(){
    while(head != nullptr){
        cout << head->data << " head " << head << " head->n " << head->next << " head->p " << head->prev << endl;
        head = head->next;
    }
}

void dList::clear(){
    while(isize){
        this->pop_front();
    }
}

int DoSMT(dList& original){
    int sum = 0;
    for(int i = 0; i < this->isize / 2; i++){
        sum += head->data * tail->data;
        original.head = original.head->next;
        original.tail = original.tail->prev;
    }
}