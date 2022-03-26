
#ifndef IOSTREAM
#  define IOSTREAM
#  include <iostream>
#endif

#ifndef EXCEPTION
#  define EXCEPTION
#  include <exception>
#endif

#ifndef LOCATE_H
#  define LOCATE_H
#  include <locale.h>
#endif

#ifndef TIME_H
#  define TIME_H
#  include <time.h>
#endif


#ifndef TREE
#  define TREE
class Tree {
private:
    class Node{
    public:
        int data;
        Node* left = nullptr;
        Node* right = nullptr;
        Node(int data, Node* left, Node* right);
        Node* find(Node* top, const int& num);
    };
    Node* root = nullptr;
    void coppy(Node* head);
    void print_tree_level(Node* top, int level);
    int GetMaxDepth(Node* root, int level);
    void remove(Node* root);
public:
    Tree();
    Tree(Tree*& tree);
    bool find(int value);
    ~Tree();
    void pushback(const int& num);
    void print();
    int GetMaxDepth();
};
#endif