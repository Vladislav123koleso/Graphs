#include "../graph/header/graph.h"
#include <iostream>

#define VERYBIGINT 1000000000 // очень большое число

void Graph::findMinDistanceDecstr(int fromVert)
{
    int distances[SIZE]; // массив меток
    for(int i=0; i<SIZE; i++) // инициализация меток
    {
        distances[i] = VERYBIGINT;
    }
    distances[fromVert] = 0;
    
    bool passed[SIZE]; // признак, что вершина окрашена
    for(int i=0; i<SIZE; i++)
    {
        passed[i] = false; // все неокрашены изначально
    }
    // принимаем стартовую вершину за текущую
    int currentVertexNum = fromVert;
    int min_dist = 0;
    while(min_dist != VERYBIGINT)
    {
        passed[currentVertexNum] = true; // окрашиваем текущую
        
        for(int i=0; i< SIZE; i++)
        {
            // для смежных ребер пересчитываем метки
            if(edgeExists(currentVertexNum,i)
               && distances[currentVertexNum] + matrix[currentVertexNum][i] < distances[i])
                    distances[i] = 
                      distances[currentVertexNum] + matrix[currentVertexNum][i];
        }
        min_dist = VERYBIGINT;
        for(int i = 0; i< SIZE; i++)
        {
            // выбираем новую текущую вершину
            if (vertexExists(i) && !passed[i] && distances[i] < min_dist) // выбор новой вершины
            {
                min_dist = distances[i];
                currentVertexNum = i;
            }
        }
    }
    
    for(int i=0; i<vertexCount; i++) // вывод результата
    {
        std::cout << "V" << i << ": " << distances[vertexes[i]] << ", ";
    }
    std::cout << std::endl;
}