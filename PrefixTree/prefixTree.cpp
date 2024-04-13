#pragma once

#include <iostream>
#define ALPHABET_SIZE 10

// Структура узла дерева
struct TrieNode
{
   struct TrieNode *children[ALPHABET_SIZE];
   // isEndOfWord - true, если ключ является концом слова
   bool isEndOfWord;
   int freq = 0;
};

// Возвращает новый узел с пустыми детьми
TrieNode *getNewNode(void)
{
    // Выделяем память по новый узел
    struct TrieNode *pNode =  new TrieNode;

    // устанавливаем флаг конца слова в false
    pNode->isEndOfWord = false; 

    // инициализируем детей нулевым уазателем
    for (int i = 0; i < ALPHABET_SIZE; i++) 
        pNode->children[i] = nullptr;

    return pNode;
}
void insert(TrieNode* root, std::string key) 
{
    TrieNode* node = root; 

    for (int i = 0; i < key.length(); i++)
    {
        // вычисляем индекс в алфите через смещение отнситьельно первой буквы
        int index = key[i] - 'a'; 

        // если указатель пустрой, т.е. детей с таким префиксом нет
        // создаем новый узел
        if (!node->children[index])
            node->children[index] = getNewNode();

        node->children[index]->freq++;
        node = node->children[index];
    }

    // помечаем последний узлел как лист, т.е. конец слова
    node->isEndOfWord = true;
}
bool search(struct TrieNode *root, std::string key) 
{ 
    struct TrieNode *node = root; 

    for (int i = 0; i < key.length(); i++) 
    {
        int index = key[i] - 'a'; 
        if (!node->children[index]) 
            return false;

        node = node->children[index]; 
    }

    return (node != nullptr && node->isEndOfWord); 
}
bool isEmpty(TrieNode* root)
{
    for (int i = 0; i < ALPHABET_SIZE; i++)
        if (root->children[i])
            return false;
    return true;
} 
TrieNode* remove(TrieNode* root, std::string key, int depth) 
{ 
    // Если дерево пустое 
    if (!root)
        return nullptr;
  
    // если дошли до конца ключа 
    if (depth == key.size()) { 
  
        // Этот узел больше не конец слова 
        if (root->isEndOfWord)
            root->isEndOfWord = false; 
  
        // Если ключ не евляется префиксом, удаляем его
        if (isEmpty(root)) { 
            delete (root);
            root = nullptr;
        }

        return root;
    }

    // Если не дошли до конца ключа, рекурсивно вызываем для ребенка 
    // соответствующего символа 
    int index = key[depth] - 'a';
    root->children[index] = remove(root->children[index], key, depth + 1); 
  
    // Если у корня нет дочернего слова 
    // (удален только один его дочерний элемент), 
    // и он не заканчивается другим словом. 
    if (isEmpty(root) && root->isEndOfWord == false) { 
        delete (root);
        root = nullptr; 
    }
  
    // возвращаем новый корень
    return root; 
}
// Возвращает true если ключ есть в дереве, иначе false
bool search(struct TrieNode *root, std::string key)
{
   TrieNode *node = root;
   for (int i = 0; i < key.length(); i++)
   {
       int index = key[i] - 'a';
       if (!node->children[index])
           return false;

       node = node->children[index];
   }

   return (node != nullptr && node->isEndOfWord);
}

// Возвращает true если root имеет лист, иначе false
bool isEmpty(TrieNode* root)
{
   for (int i = 0; i < ALPHABET_SIZE; i++)
       if (root->children[i])
           return false;
   return true;
}


// Рекурсивная функция удаления ключа из дерева
TrieNode* remove(TrieNode* root,std::string key, int depth = 0)
{
   // Если дерево пустое
   if (!root)
       return nullptr;
    // Если дошли до конца ключа
   if (depth == key.size()) {
        // Этот узел больше не конец слова
        // поэтому снимаем метку
       if (root->isEndOfWord)
           root->isEndOfWord = false;
        // Если ключ не является префиксом, удаляем его
       if (isEmpty(root)) {
           delete (root);
           root = nullptr;
       }

       return root;
   }

   // Пока не дошли до конца ключа или определили, 
   // что его нет в дереве, рекурсивно вызываем для ребенка
   // соответствующего символа
   int index = key[depth] - 'a';
   root->children[index] = remove(root->children[index], key, depth + 1);
   // Если у корня нет дочернего слова
   // (удален только один его дочерний элемент),
   // и он не заканчивается другим словом.
   if (isEmpty(root) && root->isEndOfWord == false) {
       delete (root);
       root = nullptr;
   }
    // возвращаем новый корень
   return root;
}


void findMinPrefixes(TrieNode* root, char buf[], int ind, std::string& res)
{
    if (root == NULL) return;

    if (root->freq == 1)
    {
        res += buf;
        res += ' ';
        std::cout << res << '\n';
        return;
    }
    
    for(int i = 0; i < ALPHABET_SIZE; ++i)
    {
        if(root->children[i] != nullptr)
        {
            buf[ind] = i + 'a';
            buf[ind+1] = '\0' ;     //!!! out of bounds
            findMinPrefixes(root->children[i], buf, ind+1, res);
        }
    }
}