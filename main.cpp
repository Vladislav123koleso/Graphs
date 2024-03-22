#include <iostream>
#include "BinaryTree/cpp/BinaryTree.cpp"


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
    tree.addInt(13);
    tree.addInt(10);
    tree.addInt(9);
    tree.addInt(11);
    tree.addInt(12);
    tree.addInt(14);
    tree.addInt(15);
    tree.addInt(16);
    tree.addInt(17);
    tree.addInt(18);

    //cout << tree.findNodeByData(2) << endl;
    //tree.delInt(5);
    const int size = 19;
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

    tree.print();
    return 0;
}