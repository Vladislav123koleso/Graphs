#include "../header/tree.h"


Tree::Node::Node(int _number, Node* _parent): 
    number(_number), 
    parent(_parent),
    childCount(0) { 
    
}
//
Tree::Node::~Node() {
   for(int i=0;i < childCount;i++)
   {
       delete children[i];
   }
}
//
void Tree::Node::addChild(Node* newChild){
   children[childCount++] = newChild;
}
//
Tree::Tree() {
   root = nullptr;
}
//
Tree::~Tree() {
   if(root != nullptr)
   {
       delete root;
   }
}
//
void Tree::setRoot(int number) {
   if(root != nullptr)
   {
       delete root;
       root = nullptr;
   }
   root = new Node(number);
}
//
void Tree::addNode(int parentNumber, int newNodeNumber)
{
   Node* parentNode = getNodeByNumber(parentNumber, root);
   Node* newNode = new Node(newNodeNumber, parentNode);
   parentNode->addChild(newNode);
}
//
Tree::Node* Tree::getNodeByNumber(int number, Node* current) {
   if(current->number == number)
       return current;
   for(int i=0; i<current->childCount; i++)
   {
       Node* found = getNodeByNumber(number, current->children[i]);
       if(found)
           return found;
   }
   return nullptr;
}

void Tree::delNode(int number) {
    Node* node = getNodeByNumber(number, root); // Находим вершину для удаления
    Node* parent = node->parent; // Находим её родителя

    // Цикл переброски всех детей удаляемой вершины её родителю
    for (int i = 0; i < node->childCount; ++i) {
        parent->addChild(node->children[i]); // Добавляем дочернюю вершину к родителю
    }

    node->childCount = 0; // Указываем, что у удаляемой вершины больше нет детей
    parent->delChild(node); // Удаляем вершину
}

void Tree::Node::delChild(Node* child) {
    int index = -1;
    // Цикл с нахождением индекса удаляемой вершины в массиве
    for (int i = 0; i < childCount; ++i) {
        if (children[i] == child) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        // Удаляем вершину
        delete children[index];
        
        // Сдвигаем оставшиеся вершины после индекса влево
        for (int i = index; i < childCount - 1; ++i) {
            children[i] = children[i + 1];
        }

        // Уменьшаем счетчик вершин childCount
        --childCount;
    }
}