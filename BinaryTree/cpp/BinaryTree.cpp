#pragma once
#include <iostream>
#include "../header/BinaryTree.h"
#include "../../stack/cpp/stack.cpp"

#define SIZE 20
void BinaryTree::addInt(int newData)
{
    if(root == nullptr)
    {
        root = new Node(newData);
    }
    else
    {
        Node* current = root; // начинаем с корня
        Node* newNode = nullptr;
        while(newNode == nullptr)
        {
            // если элемент меньше текущего, идем влево
            if(current->data >= newData)
            {
                if(current->leftChild != nullptr)
                {
                    current = current->leftChild;
                    continue;
                }
                // если левого узла нет, то нашли место для нового узла
                newNode = new Node(newData, current);
                current->leftChild = newNode;
            }
            // если элемент больше текущего, идем влево
            else
            {
                if(current->rightChild != nullptr)
                {
                    current = current->rightChild;
                    continue;
                }
                // если правого узла нет, то нашли место для нового элемента
                newNode = new Node(newData, current);
                current->rightChild = newNode;
            }
        }
    }

}

bool BinaryTree::isLeaf(Node* check)
{
    return ((check->leftChild == nullptr) && (check->rightChild == nullptr));
}
bool BinaryTree::isRoot(Node* check)
{
    return check == root;
}

void BinaryTree::delLeaf(Node* leaf)
{

    if (leaf == nullptr) {
        return; // Защита от нулевого указателя
    }

    if (isRoot(leaf)) {
        // Если удаляемый узел является корнем
        root = nullptr;
    } else {
        // Иначе обновляем указатель родительского узла
        Node* parent = leaf->parent;
        if (parent->leftChild == leaf) {
            parent->leftChild = nullptr;
        } else {
            parent->rightChild = nullptr;
        }
    }
    delete leaf; // Удаляем сам узел
}

void BinaryTree::delNodeWithOneChild(Node* delNode)
{
    Node* child = nullptr;
    if(delNode->leftChild == nullptr)
    {
        child = delNode->rightChild;
    }
    if(delNode->rightChild == nullptr)
    {
        child = delNode->leftChild;
    }
    if(delNode-> parent != nullptr)
    {
        if(delNode->parent->leftChild == delNode)
        {
            delNode->parent->leftChild = child;
        }
        else
        {
            delNode->parent->rightChild = child;
        }
    }
    
    if(child != nullptr)
    {
        child->parent = delNode->parent;
    }
    delNode = nullptr;
    delete delNode;
}

BinaryTree::Node* BinaryTree::findNodeByData(int findData)
{
    Node* findNode = nullptr;
    
    if(root->data == findData)
    {
        return root;
    }

    Node* current = root;
    while(findNode == nullptr)
    {
        if(current->data == findData)
        {
            findNode = current;
        }
        if(current->data > findData)
        {
            if(current->leftChild != nullptr)
            {
                current = current->leftChild;
            }
        }
        if(current->data < findData)
        {
            if(current->rightChild != nullptr)
            {
                current = current->rightChild;
            }
        }
        
    }
    return findNode;
}

void BinaryTree::delInt(int delData) {
    
    Node* delNode = findNodeByData(delData);
    // если удаляемый узел это корень
    if(isRoot(delNode))
    {
        root = nullptr;
        delete root;
    }
    // если удаляемый узел это лист
    else if(isLeaf(delNode))
    {
        delLeaf(delNode);
    }
    // если удаляемый узел имеет 1 дочерний узел
    else if((delNode->rightChild == nullptr && delNode->leftChild != nullptr) || 
    (delNode->leftChild == nullptr && delNode->rightChild != nullptr))
    {
        delNodeWithOneChild(delNode);
    }
    // если удаляемый узел имеет 2 дочерних узла
    else
    {
        Node* parent = delNode->parent;
        Node* maxLeftNode = delNode->leftChild; // максимальный дочерний узел удаляемого узла(его поставим вместо удаляемого)
        while(maxLeftNode->rightChild != nullptr)
        {
            parent = maxLeftNode;
            maxLeftNode = maxLeftNode->rightChild;
        }
        if(delNode->parent != nullptr)
        {
            // 
            if(delNode->parent->leftChild == delNode)
            {
                delNode->parent->leftChild = maxLeftNode;
            }
            else
            {
                delNode->parent->rightChild = maxLeftNode;
            }
            // если новый узел дочерний удаляемого
            if(maxLeftNode == delNode->leftChild)
            {
                maxLeftNode->rightChild = delNode->rightChild;
            }
            // если новый узел не дочерний удаляемого
            else if(maxLeftNode != delNode->leftChild)
            {
                // обновляем указатели на дочерний узел нового узла
                maxLeftNode->parent->rightChild = maxLeftNode->leftChild;
                maxLeftNode->leftChild->parent =  maxLeftNode->parent;
                // подставляем старые дочерние узлы удаляемого узла новому
                maxLeftNode->rightChild = delNode->rightChild;
                maxLeftNode->leftChild = delNode->leftChild;
            }
            maxLeftNode->parent = delNode->parent;
        }
        delNode = nullptr;
        delete delNode;
    }
}


void BinaryTree::setNewChild(Node* parent, Node* newChild) {
    // Проверяем, является ли узел корнем
    if (isRoot(parent)) {
        root = newChild;
    } else {
        // Если узел не является корнем, проверяем, является ли он левым или правым ребенком родителя
        if (parent->leftChild == nullptr) {
            parent->leftChild = newChild;
        } else {
            parent->rightChild = newChild;
        }
    }
    // Устанавливаем родителю указатель на нового ребенка
    if (newChild != nullptr) {
        newChild->parent = parent;
    }
}

void BinaryTree::symmetricWalk(int output_array[])
{
    int index = 0; // индекс текущего элемента в массиве
    Stack stack;
    Node* current = root;
    while(!stack.isEmpty() || current!=nullptr)
    {
         // Двигаемся влево, добавляя узлы в стек
        while (current != nullptr) 
        {
            stack.push(current);
            current = current->leftChild;
        }

        // Извлекаем узел из стека и добавляем его значение в выходной массив
        current = stack.pop();
        output_array[index++] = current->data;

        // Переходим к правому поддереву
        current = current->rightChild;
    }
    
}


void BinaryTree::print()
{
    Node* queue[100];
    int queueCounter = 0;
    queue[queueCounter++] = root;
    if(root != nullptr)
    {
        while(queueCounter != 0)
    {
        Node* current = queue[0];
        //удалить
        queueCounter--;
        for(int i = 0;i<queueCounter;i++)
        {
            queue[i] = queue[i+1];
        }

        if(current->parent)
        {
            std::cout << current->parent->data;
        }
        std::cout << " " << current->data << std::endl;
        if(current->leftChild)
        {
            queue[queueCounter++] = current->leftChild;
        }
        if(current->rightChild)
        {
            queue[queueCounter++] = current->rightChild;
        }
    }
    }
    
}


