#include "graph.h"
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