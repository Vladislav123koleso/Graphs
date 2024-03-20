#include <iostream>
#include "BinaryTree/cpp/BinaryTree.cpp"
#include "graph/cpp/graph.cpp"

using namespace std;

int main()
{
    BinaryTree tree;

    tree.addInt(8);
    tree.addInt(2);
    tree.addInt(1);
    tree.addInt(0);
    tree.addInt(6);
    tree.addInt(7);
    tree.addInt(4);
    tree.addInt(3);
    tree.addInt(5);

    //cout << tree.findNodeByData(2) << endl;
    //tree.delInt(5);
    const int size = 9;
    int output_array[size];
    for(int i = 0;i<size;i++)
    {
        output_array[i] = 0;
    }

    tree.symmetricWalk(output_array);
    for(int i = 0;i<size;i++)
    {
        cout << output_array[i] << endl;
    }
    return 0;
}