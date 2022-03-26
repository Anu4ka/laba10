
#include "Tree.hpp"

using namespace std;

Tree::Node::Node(int data, Node* left = nullptr, Node* right = nullptr) {
    this->data = data;
    this->left = left;
    this->right = right;
}

Tree::Node* Tree::Node::find(Node* top, const int& num){
    if (top == nullptr) {
        return nullptr;
    }
    
    Node* p;
    if (num < top->data) {
        p = find(top->left, num);
    }
    else {
        p = find(top->right, num);
    }

    if (p != nullptr) {
        return p;
    }
    return top;
}

Tree::Tree(){
    root = nullptr;
}

void Tree::coppy(Node* head){
    if(head){
        this->pushback(head->data);
        coppy(head->left);
        coppy(head->right);
    }
}

Tree::Tree(Tree*& tree){
    this->coppy(tree->root);
}

void Tree::remove(Node* root){
    if (root){
        remove(root->left);
        remove(root->right);
        delete root;
        root = NULL;
    }
}

bool Tree::find(int value){
    if(value == root->data){
        return true;
    }
    while(root != nullptr){
        if(value > root->data){
            root = root->right;
        } else {
            root = root->left;
        }
        if(root->data == value){
            return true;
        }
    }
    return false;
}

Tree::~Tree(){
    this->remove(root);
}

void Tree::pushback(const int& num){
    Node* newEl = new Node(num);
    if (root == nullptr) {
        root = newEl;
    }
    else {
        Node* to_ins = root->find(root, num);
        if (num < to_ins->data) {
            to_ins->left = newEl;
        }
        else {
            to_ins->right = newEl;
        }
    }
}

void Tree::print_tree_level(Node* top, int level) {
    if (top) {
        print_tree_level(top->left, level + 1);
        for (int i = 0; i < level; i++)
            cout << "   ";
        cout << top->data << endl;
        print_tree_level(top->right, level + 1);
    }
}

void Tree::print(){
    print_tree_level(this->root, 1);
}

int Tree::GetMaxDepth(Node* root, int level){
    if (!root) {
        return level;
    }
    return max(GetMaxDepth(root->right, level + 1), GetMaxDepth(root->left, level + 1));
}

int Tree::GetMaxDepth(){
    return this->GetMaxDepth(root, 0);
}