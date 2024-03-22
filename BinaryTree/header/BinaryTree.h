

class BinaryTree
{
public:
    // структура узла
    struct Node
    {
        Node(int d, Node* p = nullptr): data(d), parent(p)
        {
            leftChild = nullptr;
            rightChild = nullptr;
        };
        ~Node()
        {
            if(leftChild != nullptr)
            {
                delete leftChild;
            }
            if(rightChild != nullptr)
            {
                delete rightChild;
            }
        }
        
        Node* parent; // родительский узел

        Node* leftChild; // левый узел
        Node* rightChild; // правый узел

        int data; // данные 
    };
    BinaryTree()
    {
        root = nullptr;
    }
    ~BinaryTree()
    {
        if(root != nullptr)
        {
            delete root;
        }
    }

    Node* findNodeByData(int findData);
    void print();
    void addInt(int newData);
    void delInt(int delData);
    void symmetricWalk(int output_array[]); // алгоритм симметричного обхода, выводящий элементы в отсортированном порядке. 
private:
    void setNewChild(Node* child, Node* newChild = nullptr);
    void delNodeWithOneChild(Node* delNode); // удаление узла с 1 дочерним узлом
    void delLeaf(Node* leaf); // удаление узла
    bool isLeaf(Node* check); // проверка является ли узел листом
    bool isRoot(Node* check); // проверка, являтся ли узел корневым

    Node* root; // корневой узел
};