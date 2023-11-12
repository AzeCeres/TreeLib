#pragma once

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
  * \param gnode 
  */
 void Disconnect(GNode* gnode)
 {
  if (isConnectedTo(gnode))
   for (int i = 0; i < GetNumOfConnections(); ++i)
   {
    if(connections.at(i) == gnode)
      connections.pop_back(gnode);
   }
  if (gnode->isConnectedTo(this))
   gnode->connections.emplace_back(this);
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
 
};
