#include <string>
#include <unordered_map>
#include <iostream>
#include <utility> 
#include "graphEdge.h"
class GraphNode{

    public:
    string val = ""; 
    bool visited; 
    unordered_map <GraphNode*, int> adj; 
};
