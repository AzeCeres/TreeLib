// TreeLib.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "TreeLib.h"
#include <iostream>
#include <string>
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
     *                     / \
     *                    5   6
     *                         \
     *                          7
     */
    /* How the Tree *should* look after delete
     *                1
     *             /    \
     *            2      3
     */
    Node* tempNode = CreateNewNode(tree, 1); // This will become the root.
    cout << tempNode->isRoot(); //Should be true since it has no Parent
    cout << tempNode->isLeaf(); //Should be true since it has no Children yet
    CreateNewNode(tempNode, 2);
    CreateNewNode(tempNode, 3);
    Node* child4 = CreateNewNode(tempNode, 4); //All direct Children of the root
    cout << tempNode->isRoot(); //Should still be true since it still has no Parent
    cout << tempNode->isLeaf(); //Should be false since it has Children now
    cout << (tree.GetRoot()== tempNode); // Should be true, the root should not have moved out of the first position
    cout << (tempNode->GetRoot() == tempNode); // Should be true, the root should not have moved out of the first position
    cout << endl << "Depth:" << endl;
    cout << Depth(child4); //Should be 1
    cout << Depth(tempNode); //Should be 0
    CreateNewNode(child4, 5);
    Node* child6 = CreateNewNode(child4, 6);
    cout << Depth(child6); //Should be 2
    Node* child7 = CreateNewNode(child6, 7);
    cout << Depth(child7); //Should be 3
    cout << endl << "Parent Num:" << endl;
    cout << "7's parent: "<<child7->GetParent()->GetNum(); //Should be 6
    cout << "'s parent: " << child6->GetParent()->GetNum(); //Should be 4
    cout << "'s parent: " << child4->GetParent()->GetNum(); //Should be 1
    cout << " has parent? = "<<tempNode->HasParent() << endl; //Should be false / 0
    cout << endl << "Nodes in tree before deletion" << endl;
    vector<Node*> nodes = tree.GetNodes();
    for(Node* node : nodes){
     cout << node->GetNum()<< " ";// Should be 1 2 3 4 5 6 7
    }
 cout << endl << "Children of root before deletion" << endl;
    nodes = tree.GetRoot()->GetChildren();
    for(Node* node : nodes){
     cout << node->GetNum()<< " ";// Should be 2 3 4
    }
    child4->DeleteNode();
     cout << endl << "Nodes in tree after deletion" << endl;
    nodes = tree.GetNodes();
    for(Node* node : nodes){
     cout << node->GetNum()<< " ";// Should be 1 2 3
    }
 cout << endl << "Children of root after deletion" << endl;
 nodes = tree.GetRoot()->GetChildren();
    for(Node* node : nodes){
     cout << node->GetNum()<< " ";// Should be 2 3
    }
    // Expected output:
    // 111011
    // Depth:
    // 1023
    // Parent Num:
    // 7's parent: 6's parent: 4's parent: 1 has parent? = 0
    // 
    // Nodes in tree before deletion
    // 1 2 3 4 5 6 7
    // Children of root before deletion
    // 2 3 4
    // Nodes after deletion
    // 1 2 3
    // Children of root after deletion
    // 2 3
    
    return 0;
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
