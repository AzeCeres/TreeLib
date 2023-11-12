// TreeLib.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "TreeLib.h"
#include "GraphLib.h"
#include <iostream>
#include <string>
using namespace std;

/**
 * Test Function to see if the library is working properly
 *
 */
void TestTreeLibrary()
{
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
}

/**
 * \brief A test function to see that the graph library is behaving like expected.
 */
void TestGraphLibrary()
{
 /// How the graph should look:
 ///      1---7
 ///    /   \  \
 ///   2-----3--6    8
 ///    \   / \ |
 ///      4-----5
 GNode* node1 = new GNode();
 cout << node1->GetValue();
 node1->SetValue(1);
 cout << '\n' << node1->GetValue();
 GNode* node2 = new GNode(2, node1);
 GNode* node3 = new GNode(3, node1);
 node2->AddConnection(node3);
 GNode* node4 = new GNode(4, node2);
 node4->AddConnection(node3);
 GNode* node5 = new GNode(5, node3);
 node5->AddConnection(node4);
 GNode* node6 = new GNode(6, node5);
 node6->AddConnection(node3);
 GNode* node7 = new GNode(7, node1);
 GNode* node8 = new GNode(8);

 cout << "\nNode 3 Checks\n";
 cout << node3->isLonely(); // Should be False, It has multiple connections
 cout << node3->GetNumOfConnections(); // Should be 5
 vector<GNode*> node3Connections = node3->GetConnections();
 for (auto connection : node3Connections)
 {
  cout << connection->value << " ";
 } // Should be 1 2 4 5 6
 cout << node3->isConnectedTo(node8); // False
 cout << node3->isConnectedTo(node1); // True
 cout << node3->isConnectedTo(node3); // False
 node3->Disconnect(node1);
 node3Connections = node3->GetConnections();
 cout << "\nNode 3 Checks after disconnecting from node 1\n";
 for (auto connection : node3Connections)
 {
  cout << connection->value << " ";
 } // Should be 2 4 5 6
 cout << node3->isConnectedTo(node1); // False
 cout << node1->isConnectedTo(node3); // False
 
 
}
/// Expected Output
/// -2147483648 (INT_MIN, since that's the default value)
/// 1
/// Node 3 Checks
/// 051 2 3 4 5 6 010
/// Node 3 Checks after disconnecting from node 1
/// 2 4 5 6 00
int main() {
  cout<<"Testing Tree Library \n";
  TestTreeLibrary();
  cout<<"\nTesting Graph Library \n";
  TestGraphLibrary();
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
