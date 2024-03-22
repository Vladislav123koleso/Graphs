#pragma once
#include "../../BinaryTree/cpp/BinaryTree.cpp"
#define MAX 1000

class Stack
{
public:
    BinaryTree::Node* m_items[MAX];
    
    Stack(): m_top(-1){}
    
    void push(BinaryTree::Node* x);
    
    BinaryTree::Node* pop();
    BinaryTree::Node* peek();

    bool isFull();
    bool isEmpty();
private:
    int m_top;
};