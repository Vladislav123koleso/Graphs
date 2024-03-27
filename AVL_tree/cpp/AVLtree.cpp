#include "../header/AVLtree.h"
#include <queue>

size_t AVL::height(Node* node)
{
    return node ? node->height : 0;
}

int AVL::bfactor(Node* node)
{
   return height(node->right) - height(node->left);
}

void AVL::fix_height(Node* node)
{
   size_t h_left = height(node->left);
   size_t h_right = height(node->right);

   node->height = (h_left > h_right ? h_left : h_right) + 1;
}

AVL::Node* AVL::rotateRight(Node* node)
{
   Node* q = node->left;

   node->left = q->right;
   q->right = node;
   fix_height(node);
   fix_height(q);

   return q;
}

AVL::Node* AVL::rotateLeft(Node* node)
{
   Node* q = node->right;

   node->right = q->left;
   q->left = node;
   fix_height(node);
   fix_height(q);

   return q;
}


AVL::Node* AVL::balance(Node* const node)
{
   // вычисляем правильную высоту для узла
   fix_height(node);

   // Балансируем дерево в зависимости от фактора балансировки
   if (bfactor(node) == 2)
   {
       if (bfactor(node->right) < 0)
           node->right = rotateRight(node->right);
       return rotateLeft(node);
   }

   if (bfactor(node) == -2)
   {
       if (bfactor(node->left) > 0)
           node->left = rotateLeft(node->left);
       return rotateRight(node);
   }

   // балансировка не нужна
   return node;
}

const AVL::Node* AVL::bfs(const int& key) const
{
    if(root == nullptr)
    {
        return nullptr;
    }
    // Создаем пустую очередь для добавления узлов с одинакового уровня -
    // имеющие одинаковую высоту
    std::queue<Node*> q;
    q.push(root);
    while (q.empty() == false)
    {
        Node* node = q.front();

        q.pop();

        if(node->key == key)
        {
            return node;
        }
        if(node->left != nullptr)
        {
            q.push(node->left);
        }
        if(node->right != nullptr)
        {
            q.push(node->right);
        }
    }
    
}

const AVL::Node* AVL::dfs(const Node* node, const int& key) const
{
    if (node == nullptr || node->key == key) {
        return node;
    }

    // Поиск в левом поддереве
    const Node* left_result = dfs(node->left, key);
    if (left_result != nullptr) {
        return left_result;
    }

    // Поиск в правом поддереве
    return dfs(node->right, key);
}

void AVL::insert(int&& key)
{
  Node* node = new Node(key);
  root = insert(root, node);
}

AVL::Node* AVL::insert(Node* root, Node* const node)
{
   if(!root)
       return node;

   if(node->key < root->key)
       root->left = insert(root->left, node);
   else
       root->right = insert(root->right, node);

   return balance(root);
}