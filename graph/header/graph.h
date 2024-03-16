#define SIZE 10

class Graph
{
public:
    Graph();
    void depth(int start); // функция обхода графа по вершинам в глубину
    void width(int start); // функция обхода графа по вершинам в ширину

    void addVertex(int vnumber); // добавление вершины
    void addEdge(int v1, int v2, int weight); // добавление ребра

    int findPathCount(int start, int end); // функция поиска кол-ва всех возможных путей между 2умя вершинами
    int depthInnerForFindPath(int current,int end, bool visited[]);

    void findMinDistanceDecstr(int fromVert); // Алгоритм Дейкстры
    void findMinDistancesFloyd(); // алгоритм Флойда-Уоршела

    void deleteVertex(int vnumber);
    void deleteEdge(int v1, int v2);
private:
    void depthInner(int current, bool visited[]);

    bool edgeExists(int v1, int v2); // проверка существования ребра
    bool vertexExists(int v); // проверка существования вершины

    int matrix[SIZE][SIZE]; // матрица смежности
    int vertexes[SIZE]; // хранилище вершин
    int vertexCount; // кол-во добавленных вершин
};