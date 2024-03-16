#include <iostream>
#include "../graph/header/graph.h"

#define VERYBIGINT 1000000000

void Graph::findMinDistancesFloyd()
{
    int weights[SIZE][SIZE]; // матрица путей
    // инициализаци матрицы
    for(int i=0; i< SIZE; i++)
    {
        for(int j =0; j <SIZE; j++)
        {
            if(i == j)
            {
                weights[i][j] = 0; // путь до самой себя равен 0
            } else {
                if(!edgeExists(i,j))
                {
                    weights[i][j] = VERYBIGINT; // если ребра нет
                } else {
                    weights[i][j] = matrix[i][j]; // если ребро есть
                }
            }
        }
    }
    
    for(int k=0; k<vertexCount; k++) // итерации по k
    {
        int ck = vertexes[k]; // возьмем номер вершины
        for(int i = 0; i<vertexCount; i++)
        {
            if(i == k)
                continue;
            int ci = vertexes[i]; 
            for(int j = 0; j<vertexCount;j++)
            {
                if(j == k)
                    continue;
                int cj = vertexes[j];
                if(weights[ci][ck] + weights[ck][cj] < weights[ci][cj]) {
                    // пересчет мматрицы путей
                    weights[ci][cj] = weights[ci][ck] + weights[ck][cj];
                }
            }
        }
    }
    
    for(int i = 0; i<vertexCount ; i++)  
    {
        // вывод всех минимальных путей от вершины '0'
        std::cout << "V" << i << ": " << weights[0][vertexes[i]] << ", ";
    }
}

