#pragma once
#include <iostream>
#include <vector>

class GNode;
using namespace std;

/**
 * \brief Like a Tree node, but for a graph instead
 */
class GNode
{
 public:
 int value{INT_MIN};
 vector<GNode*> connections;

 /**
  * \brief A function to see if the node has any connections.
  * \return False if it has connections, True if it has none.
  */
 bool isLonely() const {
  return connections.empty();
 }

 /**
  * \brief A function to get all the connections of a given node.
  * \return A vector of all connections
  */
 vector<GNode*> GetConnections() const {
  return connections;
 }
 int GetNumOfConnections() const{
  return connections.size();
 }
 int GetValue() const {
  return value;
 }
 void SetValue(int inValue) {
  value = inValue;
 }

 /**
  * \brief Connects this gnode and the given gnode. Adds each other to their respective connections if they aren't already connected
  * \param gnode 
  */
 void AddConnection(GNode* gnode) {
  if (isConnectedTo(gnode)) return;
  connections.push_back(gnode);
  if (gnode->isConnectedTo(this)) return;
  gnode->connections.push_back(this);
 }
 /**
  * \brief Checks if "this" and the given "gnode" is connected. (if "gnode" is in "this's" connection vector)
  * \param gnode
  * \return True if "gnode" exists in "connections", false if not
  */
 bool isConnectedTo(GNode* gnode)
 {
  for (auto connedGnode : connections){
   if (connedGnode == gnode)
    return true;
  }
  return false;
 }

 /**
 * \brief Disconnects this gnode and the given gnode. removes each other from their respective "connections" if they aren't already disconnected
 * Doesn't work if the given gnode isn't connected to this gnode
 * \param gnode 
 */
 void Disconnect(GNode* gnode) {
  // Use the erase-remove idiom for disconnecting both nodes
  auto it = remove(connections.begin(), connections.end(), gnode);
  connections.erase(it, connections.end());

  // Remove the reverse connection
  it = remove(gnode->connections.begin(), gnode->connections.end(), this);
  gnode->connections.erase(it, gnode->connections.end());
 }
 explicit GNode() {
  this->value = INT_MIN;
 }
 explicit GNode(int value) {
  this->value = value;
 }
 explicit GNode(int value, GNode* connedGNode) {
  this->value = value;
  this->AddConnection(connedGNode);
 }
 void BFS() const {
  queue<const GNode*> bfsQueue;
  vector<const GNode*> visited;

  bfsQueue.push(this);
  visited.push_back(this);

  while (!bfsQueue.empty()) {
   const GNode* current = bfsQueue.front();
   bfsQueue.pop();

   // Process the current node
   cout << current->value << " ";

   // Enqueue unvisited neighbors
   for (const GNode* neighbor : current->connections) {
    if (find(visited.begin(), visited.end(), neighbor) == visited.end()) {
     bfsQueue.push(neighbor);
     visited.push_back(neighbor);
    }
   }
  }
  cout << endl;
 }
};
static void DeleteGNode(GNode* gnode) {
 // Disconnect this node from its neighbors
 for (int i = gnode->connections.size() - 1; i >= 0; --i){ //reversed for loop to avoid skipping over any disconnections
  gnode->connections.at(i)->Disconnect(gnode);
 }

 // Clear the connections vector
 gnode->connections.clear();

 // Delete this node
 delete gnode;
}


