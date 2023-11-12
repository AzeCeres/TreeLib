#pragma once
#include <climits>
#include <queue>
#include <string>
#include <vector>
using namespace std;
class Tree;
Tree newTree();
class Node {
public:
    int num{INT_MIN};
    vector<Node*> children;
    Node* parent{nullptr};
    Tree* tree{nullptr};
    bool isLeaf() const {
        return children.empty();
    }
    bool isRoot() const; // Declared here
    Node* GetRoot(); // Declared here
    vector<Node*> GetChildren() const {
        return children;
    }
    int GetNum() const {
        return num;
    }
    void SetNum(int value) {
        num = value;
    }
    bool HasParent() const {
        return parent != nullptr;
    }
    Node* GetParent() const {
        if (HasParent())
            return parent;
        return nullptr;
    }
    void SetParent(Node* node) {
        parent = node;
    }
    Tree* GetTree() const {
        return tree;
    }
    void SetTree(Tree* tree) {
        this->tree = tree;
    }
    int GetDepth();
    void DeleteNode();
    void RemoveChild(Node* const childToRemove){
        for (int i = 0; i < children.size(); ++i) {
            if (children.at(i) != childToRemove) continue;
            children.erase(children.begin() + i);
            break;
        }
    }
};
class Tree {
public:
    vector<Node*> nodes;
    Node* GetRoot(); // Declared here
    vector<Node*> GetNodes() const {
        return nodes;
    }
    int GetSize() const {
        return nodes.size();
    }
    bool isEmpty() const {
        return nodes.empty();
    }
    void DeleteTree() {
        for (Node* node : nodes) {
            node->DeleteNode();
        }
    }
    void RemoveNode(Node* nodeToRemove)
    {
        for (int i = 0; i < nodes.size(); ++i) {
            if (nodes.at(i) == nodeToRemove) {
                nodes.erase(nodes.begin() + i);
                break;
            }
        }
    }
};
Node* Tree::GetRoot() { //Defined for Tree

    return nodes.at(0);
}
Node* Node::GetRoot(){ //Defined for Node
    return tree->nodes.at(0);
}
inline bool Node::isRoot() const{ //Defined for Node
    return tree->nodes.at(0) == this;
}

Tree newTree(){
    Tree* temp = new Tree;
    temp->nodes.clear();
    return *temp;
}

Node* newNode(int value) { //todo move into Node class
    Node* temp = new Node;
    temp->num = value;
    return temp;
}
Node* CreateNewNode(Node* &parentNode, int value) { 
    Node* tempNode = newNode(value);
    tempNode->num = value;
    tempNode->SetParent(parentNode);
    Tree* tempTree = parentNode->tree;
    tempNode->tree = tempTree;
    (tempTree->nodes).push_back(tempNode);
    (parentNode->children).push_back(tempNode);
    return tempNode;
}
Node* CreateNewNode(Tree &tree, int value) { 
    if (tree.nodes.empty()) {
        // If the tree is empty, create a root
        Node* tempNode = newNode(value);
        tempNode->tree = &tree; // Set the tree pointer for the root node
        tree.nodes.push_back(tempNode);
        return tempNode;
    } else {
        Node* tempNode = nullptr;
        for (int i = 0; i < tree.nodes.size(); ++i) {
            if (tree.nodes.at(i) == nullptr) {
                // Initialize the tree.nodes vector with nullptrs
                tempNode = CreateNewNode(tree.nodes.at(i), value);
                break;
            }
        }

        if (tempNode == nullptr) {
            // If no nullptr was found, create a new node
            tempNode = newNode(value);
            tempNode->tree = &tree;
            tree.nodes.push_back(tempNode);
        }
        return tempNode;
    }
}
void Node::DeleteNode() {
    if (this == nullptr) {
        return;
    }

    // Remove the node from its parent's children list
    if (parent) {
        parent->RemoveChild(this);
    }
    if(tree){
        // Remove the node from the tree's nodes list
        tree->RemoveNode(this);
    }
    // Recursively delete the node's children
    for (Node* child : children) {
        child->DeleteNode();
    }

    // Delete the node itself
    delete this;
}
int Depth(Node* node) {
    if (node->isRoot())
        return 0; // Root nodes have depth 0.

    int depth = 0;
    Node* currentNode = node;
    
    while (currentNode->GetParent() != nullptr) {
        depth++;
        currentNode = currentNode->GetParent();
    }
    return depth;
}

int Node::GetDepth()  {
    return Depth(this);
}