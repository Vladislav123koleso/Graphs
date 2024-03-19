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
            
            void addChild(Node* newChild); // добавление дочернего узла
            void delChild(Node* child); // удаление указанного дочернего узла текущего узла
            
            
        };
        Tree();
        ~Tree();
    
        void setRoot(int number); // установка корневого узла
        void addNode(int parentNumber, int newNodeNumber); // добавление нового узла
        // parentNumer - номер родительского узла для создаваемого узла / newNodeNumber - номер нового создаваемого узла
        
        void delNode(int nodeNumber); // удаление узел со всеми дочерними узлами
        
        friend void print(Tree& tree); // вывод дерева
    
    private:
        Node* getNodeByNumber(int number, Node* current); // поиск узла по его номеру
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