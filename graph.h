#define SIZE 10

class Graph
{
public:
    Graph();
    void addVertex(int vnumber); // добавление вершины
    void addEdge(int v1, int v2, int weight); // добавление ребра
    void deleteVertex(int vnumber);
    void deleteEdge(int v1, int v2);
private:
    int matrix[SIZE][SIZE]; // матрица смежности
    int vertexes[SIZE]; // хранилище вершин
    int vertexCount; // кол-во добавленных вершин
};