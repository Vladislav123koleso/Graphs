#define SIZE 10

class Graph
{
public:
    Graph();
    void depth(int start); // функция обхода графа по вершинам в глубину
    void width(int start); // функция обхода графа по вершинам в ширину
    void addVertex(int vnumber); // добавление вершины
    void addEdge(int v1, int v2, int weight); // добавление ребра
    void deleteVertex(int vnumber);
    void deleteEdge(int v1, int v2);
private:
    void depthInner(int current, bool visited[]);

    int matrix[SIZE][SIZE]; // матрица смежности
    int vertexes[SIZE]; // хранилище вершин
    int vertexCount; // кол-во добавленных вершин
};