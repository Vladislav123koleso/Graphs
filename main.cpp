#include <iostream>
#include "BinaryTree/cpp/BinaryTree.cpp"
#include "graph/cpp/graph.cpp"

using namespace std;

int main()
{
    BinaryTree tree;

    tree.addInt(0);
    tree.addInt(2);
    tree.addInt(1);
    tree.addInt(3);
    tree.addInt(5);

    //cout << tree.findNodeByData(2) << endl;
    tree.delInt(1);
    return 0;
}