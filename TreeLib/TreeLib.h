#pragma once
#include <climits>
#include <vector>
using namespace std;

void hello();

class Tree;

class Node {
public:
    int num{INT_MIN};
    vector<Node*> children;
    Tree* tree;
};
class Tree {
public:
    vector<Node*> nodes;
};
Node* getRoot(Tree tree)
{
    if(tree.nodes.empty()) return nullptr;
    tree.nodes.at(0);
}
Tree newTree()
{
    Tree* temp = new Tree;
    temp->nodes.clear();
    return *temp;
}
bool isRoot(Node* node);
bool isLeaf(Node* node);
Node* newNode(int value) {
    Node* temp = new Node;
    temp->num = value;
    return temp;
}
Node* CreateNewNode(Node* &parentNode, int value) {
    Node* tempNode = newNode(value);
    tempNode->num = value;
    Tree* tempTree = parentNode->tree;
    tempNode->tree = tempTree;
    (tempTree->nodes).push_back(tempNode);
    (parentNode->children).push_back(tempNode);
    return tempNode;
}
Node* CreateNewNode(Tree &tree, int value) {
    if (!tree.nodes.empty()) {
        Node* tempNode{nullptr};
        for (int i = 0; i < tree.nodes.size(); ++i) {
            if (tree.nodes.at(i) != nullptr) //todo Unfinished logic
                continue;
            tempNode = CreateNewNode(tree.nodes.at(i), value);
        }
        return tempNode;
    }
    // If the tree is empty it has to create a root
    Node* tempNode = newNode(value);
    tempNode->num = value;
    (tree.nodes).push_back(tempNode);
    return tempNode;
}
int Depth(Node node);