#include <iostream>
#include <string>
#include <unordered_set>
#include <utility>
#include <deque>
#include <stack>
#include <random>
#include <ctime>
#include <stack>
#include <cstdlib>
#include "GraphNode.h"
#include "weightedGraph.h"


void WeightedGraph::addNode(string nodeVal){
    GraphNode vertex = new GraphNode; 
    vertex->val = nodeVal; 
    WeightedGraph->nodes.push_back(vertex); 
} 

void WeightedGraph::addWeightedEdge(GraphNode*first, GraphNode*second, int edgeWeight){
   graphEdge edge = new graphEdge; 
   edge->n_first = first; 
   edge->n_second = second; 
   edge->n_weight = edgeWeight; 
   first->adj.push_back(second); 
   WeightedGraph->edges.push_back(edge); 
}

unordered_set<GraphNode*> WeightedGraph::getAllNodes(){
    unordered_set<GraphNode*> r_wing; 

    for(int i = 0; i < WeightedGraph->nodes.size(); it != WeightedGraph->nodes.end(); it++)
    {
        r_wing.insert(it); 
    }
    return r_wing; 
}

unordered_set<GraphEdge*> WeightedGraph::getAllEdges(){
    unordered_set<graphEdge*> e_wing; 
    for(auto it = WeightdGraph->edges.begin(); it != WeightedGraph->edges.end(); it++)
    {
        e_wing.insert(it);    
    }
    return e_wing; 
}

int randomNumberGen(){
    random rand = new random(); 
    rand = ((double) rand() / (RAND_MAX)) +1; 
    return rand; 
}

void WeightedGraph::removeDirectedEdge(GraphNode* first, GraphNode* second){
    unordered_set<graphEdge*> e_node;  
    e_node = WeightedGraph->edges; 
    for(int it = 0; it < e_node.size(); it++)
    {
        if(first == e_node[it]->n_first && second == e_node[it]->n_second)
            e_node->edges.erase(e_node[it]);
    }
    first->adj.erase(second); 
}

WeightedGraph*WeightedGraph::createdRandomWeightedGraph(int n){
    int coin = 0; 
    srand((unsigned) time(0));
    int randomNumber = 0;  
    for(int i = 0; i < n; ++i){
        addNode(to_string(n)); 
    }
    for(auto it = WeightedGraph->nodes.begin(); it!= WeightedGraph->nodes.end(); it++)
    {
        for(auto jt = WeightedGraph->nodes.rbegin(); jt != WeightedGraph->nodes.rend(); i++){
            coin = randomNumberGen(); 
            randomNumber = (rand() % (n-1); 
            if(coin == 2)
                addWeightedEdge(it, jt, randomNumber); 
        }
    }
}

WeightedGraph*WeightedGraph::createLinkedList(int n){
    unordered_set<GraphNode*> graph;
    graph = getAllNodes(); 
    for(auto it = graph.begin(); it != graph.end(); it++){ 
        if(i > 1){
            addWeightedEdge(it, it + 1, 1); 
        }
    }
}

unordered_map<graphEdge*>WeightedGraph::djkstras(GraphNode*start)
{
    unordered_map<graphEdge*>path; 
    vector<GraphNode*> discovered; 
    stac k<GraphNode*>stacc; 
    graphEdge*curr; 
    graphEdge*chosen; 
    GraphNode*u; 
    unordered_set<graphEdge*>edges = getAllEdges(); 
    int lowestVal = 0; 
    stacc.push(start); 

    while(!stacc.empty())
    {
        u = stacc.top(); 
        path.push_back(tower.pop()); 
        if(discovered[u] -> visited == true)
            continue; 
        discovered[u]->visited = true; 
    for(auto it = u->adj.begin(); it!= u->adj.end(); it++){
       curr = edges.find(pair<u, edges->n_weight>); 
       if(lowestVal == 0 ){
            lowestVal = edges->n_weight;
            chosen = curr;  
        } else if(lowestVal > edges->n_weight){
            lowestVal = edges->n_weight; 
            chosen = curr;   
        }
        stacc.push(u); 
    }path.insert(chosen); 

    }
    return path; 
}


int main(){
    return 0; 
} 