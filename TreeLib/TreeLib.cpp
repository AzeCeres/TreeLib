// TreeLib.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "TreeLib.h"
#include <iostream>
using namespace std;
/**
 * Test Function to see if the library is working properly
 *
 */
int main() {
    Tree tree = newTree();
    /* How the Tree *should* look
     *                 1
     *             /   |   \
     *            2    3    4
     */
    Node* tempNode = CreateNewNode(tree, 1); // This will become the root.
    cout << isRoot(tempNode); //Should be true since it has no Parent
    cout << isLeaf(tempNode); //Should be true since it has no Children yet
    CreateNewNode(tempNode, 2);
    CreateNewNode(tempNode, 3);
    CreateNewNode(tempNode, 4); //All direct Children of the root
    cout << isRoot(tempNode); //Should still be true since it still has no Parent
    cout << isLeaf(tempNode); //Should be false since it has Children now
    cout << (getRoot(tree)== tempNode); // Should be true, the root should not have moved out of the first position
    //Expected output 11101
    return 0;
}

bool isRoot(Node* node) {
    if (node == node->tree->nodes.at(0))
        return true;
    return false;
}
bool isLeaf(Node* node) {
    if (node->children.empty())
        return true;
    return false;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
