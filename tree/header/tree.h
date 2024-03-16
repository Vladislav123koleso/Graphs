#ifndef __TREE_H_
#define __TREE_H_
#include <iostream>
#include <queue>

#define SIZE 10

class Tree { // класс дерева
    public:
        struct Node { // структура узла
            Node(int _number, Node* _parent = nullptr);
            ~Node();
            
            int number; // номер мершины
            
            Node* parent; // родительская вершина
            Node* children[SIZE]; // список дочерних вершин
            int childCount; // количество детей
            
            void addChild(Node* newChild);
            void delChild(Node* child);
            
            void dummy(void* param);
        };
        Tree();
        ~Tree();
    
        void setRoot(int number);
        void addNode(int parentNumber, int newNodeNumber);
        
        void delNode(int nodeNumber);
        void dummy(int nodeNumber);
        
        friend void print(Tree& tree); // Объявление функции print как друга класса Tree
    
    private:
        Node* getNodeByNumber(int number, Node* current);
        Node* root;
};
#endif


// Определение функции print вне класса Tree
void print(Tree& tree)
{
    if(tree.root == nullptr)
    {
        std::cout << "Дерево пустое" << std::endl;
        return;
    }
    std::queue<Tree::Node*> q;
    q.push(tree.root);
    while(!q.empty())
    {
        Tree::Node* current = q.front();
        q.pop();

        std::cout << current->number << " ";

        for(int i = 0;i < current-> childCount;i++)
        {
            q.push(current->children[i]);
        }
    }
    std::cout << std::endl;
}