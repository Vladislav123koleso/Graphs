
class AVL
{
public:
    struct Node
    {
        int key; // ключ
        Node* left; // указатель на левый дочерний узел
        Node* right; // указатель на правый дочерний узел

        size_t height; // значение высоты относительно корня, для выполнения балансировки.
    
        Node(int& k) {key = k, left = right = nullptr, height = 0;}
        Node(int&& k) {key = k, left = right = nullptr, height = 0;}
    };

    size_t height(Node* node); // обертка для работы с пустыми деревьями
    
    int bfactor(Node* node); // находим разницу высот

    void fix_height(Node* node); // Исправление высоты

    Node* rotateLeft(Node* node); // поворот влево
    Node* rotateRight(Node* node); // поворот вправо

    Node* balance(Node* const node); // выполняем балансировку дерева вокруг узла

    // поиск в ширину
    const Node* bfs(const int& key) const;
    // поиск в глубину
    const Node* dfs(const Node* node, const int& key) const;
    // вставка
    void insert(int&& key);
    Node* insert(Node* root, Node* const node);
private:
    Node* root;
};
