#include "../header/graph.h"
#include <iostream>

Graph :: Graph()
{
    for(int i =0; i < SIZE;i++)
    {
        for(int j =0; j < SIZE;j++)
        {
            matrix[i][j] = 0;
        }
    }
    vertexCount = 0;
}

// проверка существования ребра
bool Graph::edgeExists(int v1, int v2)
{
    return matrix[v1][v2] > 0;
}
// проверка существования вершины
bool Graph::vertexExists(int v)
{
    for(int i=0;i<vertexCount;i++)
       if(vertexes[i] == v)
          return true;
    return false;
}

void Graph :: depth(int start)
{
    // инициализация массива вершин, которые будут пройдены
    bool visited[SIZE];
    for(int i = 0; i < SIZE; i++)
    {
        visited[i] = false;
    }
    // вызов рекурсии 
    depthInner(start, visited);

}

void Graph :: depthInner(int current, bool visited[])
{
    // внутри рекурсии 
    // выводим себя
    std::cout << "V" << current << ", ";
    // запомнить что проходили
    visited[current] = true;
    // зайти в смежную непосещенную
    for(int i = 0;i < vertexCount;i++)
    {
        int vnum = vertexes[i]; // номер вершины
        // проверка смежности вершин с текущей вершиеной по массиву смежности
        if(matrix[vnum][current] != 0 && visited[vnum] != true)
        {
            depthInner(vnum, visited);
        }
    }
}

void Graph :: width(int start)
{
    //инициализация очереди и списка посещенных вершин
    int queue[SIZE];
    int queueCount = 0; // счетчик кол-ва элементов в очереди

    bool visited[SIZE];
    for(int i = 0; i < SIZE;i++)
    {
        visited[i] = false;
    }

    queue[queueCount++] = start;
    // цикл по очереди
    while(queueCount > 0)
    {
        // берем верхний элемент, выводим и удаляем из очереди
        int currentNum = queue[0];
        queueCount--;
        for(int i = 0;i < queueCount;i++)
        {
            queue[i] = queue[i+1];
        }
        std::cout << "V" << currentNum << ", ";
        visited[currentNum] = true;
        // кладем в очередь все смежные непосещенные
        for(int i = 0;i < vertexCount;i++)
        {
            int vnum = vertexes[i];

            int j = 0;
            // проверка не находится ли вершина уже в очереди
            for(;j < queueCount;j++)
            {
                if(queue[j] == vnum)
                {
                    break;
                }
            }

            if(j < queueCount)
            {
                continue;
            }

            if(matrix[vnum][currentNum] != 0 && visited[vnum] != true)
            {
                queue[queueCount++] = vnum;
            }
        }
    }
}

int Graph :: findPathCount(int start, int end)
{
    bool visited[SIZE];
    for(int i = 0;i < SIZE;i++)
    {
        visited[i] = false;
    }

    int result = depthInnerForFindPath(start, end, visited);
    return result;
}
int Graph :: depthInnerForFindPath(int current, int end, bool visited[])
{
    if(current == end)
        return 1; // Найден путь до конечной вершины
    
    int result = 0;
    visited[current] = true;
    
    // Перебираем смежные вершины
    for(int i = 0; i < vertexCount; i++)
    {
        int vnum = vertexes[i];
        if(matrix[vnum][current] != 0 && !visited[vnum])
        {
            result += depthInnerForFindPath(vnum, end, visited);
        }
    }

    visited[current] = false; // Возвращаем вершину как непосещенную для других путей
    return result;

}

void Graph :: addVertex(int vnumber)
{
    vertexes[vertexCount++] = vnumber;
}

void Graph :: addEdge(int v1, int v2, int weight)
{
    matrix[v1][v2] = weight;
    matrix[v2][v1] = weight;
}

void Graph :: deleteVertex(int vnumber)
{
    for(int i = 0; i < vertexCount;i++)
    {
        
        if(vertexes[i] == vnumber)
        {
            
            for(int j = i; j < vertexCount;j++)
            {
                vertexes[j] = vertexes[j+1];
                vertexes[j + 1] = 0;
            }
            for(int k = 0; k < vertexCount; k++)
            {
                matrix[k][i] = 0;
                matrix[i][k] = 0;
            }
            vertexCount--;
        }
    }
}

void Graph :: deleteEdge(int v1, int v2)
{
    matrix[v1][v2] = 0;
    matrix[v2][v1] = 0;
}