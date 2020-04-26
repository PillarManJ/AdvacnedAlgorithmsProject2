#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include "GraphNode.h"

template <class T>
class DirectedGraph{
    public:
    DirectedGraph(string s)
    GraphNode(); 
    vector <GraphNode*> adj
    void addNode(T val);
    void addDEdge(T first, T second); 
    void removeDEdge(T first, T second); 
    DirectedGraph*DirectedGraph createRandomDAGIter(T first);
    unordered_set <GraphNode*> getAllNodes(); 
};