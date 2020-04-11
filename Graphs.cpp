#include <iostream>
#include <string> 
#include <queue>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <utility>

using namespace std;


class GraphNode{
    public:
    string val = ""; 
    unordered_map <GraphNode*, int> adj; 
};

class Graph
{

//string val = ""; 
vector <GraphNode*> adjacency_list;

public:
Graph(string s);

vector <GraphNode*> adj; 

void addNode(string nodeVal); 

void addUDNodeEdge(GraphNode*first,GraphNode*second); 

void removeUDNodeEdge(GraphNode* first, GraphNode* second);

vector<GraphNode> BFS(GraphNode*node);

unordered_set<GraphNode*> getallNodes();

}; 

void Graph::addNode(string nodeVal)
{
GraphNode*vertex = new GraphNode();
    vertex->val = nodeVal; 
    this->adjacency_list.push_back(vertex);  
}

void Graph::addUDNodeEdge(GraphNode*first, GraphNode*second){
    
    pair <GraphNode*, int> pair_one;
    //Create the pair 
    //Connect the first node to the second and add the pair to the adjacency list ;
    pair_one.first = second; 
    pair_one.second = 1; 
    first->adj.insert(pair_one);
    //Create another pair.
    //Connect the second node to the first and add the pair to the adjacency list ; 
    pair <GraphNode*, int> pair_two; 
    pair_two.first = first; 
    pair_two.second = 1;
    second->adj.insert(pair_two);  

}

void Graph::removeUDNodeEdge(GraphNode*first, GraphNode*second){
    //Erase first
    first->adj.erase(second);
    //Erase second
    second->adj.erase(first); 
}


unordered_set<GraphNode*> Graph::getallNodes(){
   unordered_set <GraphNode*> r_wing; 
   for (int i = 0; i < adjacency_list.size(); ++i){
   // for( auto it = Graph->adjacency_list.begin(); it != Graph->adjacency_list.end(); ++it)
           r_wing.insert(adjacency_list[i]); 
   //}
    return r_wing; 
}

void iterate_Graph(unordered_set<GraphNode*> squad){
    for( auto it = Graph->adjacency_list.begin; it!= Graph->adjacency_list.end ++it)
    {
        cout  << " " << ": " << it->val;
    }
}

int main(){

    return 0; 
}