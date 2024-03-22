#pragma once
#include "../header/stack.h"


bool Stack::isFull()
{
    return m_top >= (MAX-1);
}
bool Stack::isEmpty()
{
    return m_top < 0;
}

void Stack::push(BinaryTree::Node* x)
{
    if(!isFull())
    {
        ++m_top;
        m_items[m_top] = x;
    }
}

BinaryTree::Node* Stack::pop()
{
    if(!isEmpty())
    {
        BinaryTree::Node* x = m_items[m_top];
        --m_top;
        return x;
    }
    else
    {
        return nullptr;
    }
}

BinaryTree::Node* Stack::peek()
{
    if(!isEmpty())
    {
        BinaryTree::Node* x = m_items[m_top];
        --m_top;
        return x;
    }
    else
    {
        return nullptr;
    }
}