#include <iostream>
#include <string> 
#include <queue>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <stack> 
#include <list> 
#include <random> 
#include "GraphSearch.h"
#include "GraphNode.h"

using namespace std;

/*
class GraphNode{
    public:
    string val = ""; 
    unordered_map <GraphNode*, int> adj; 
};*/

class Graph
{

//string val = ""; 
//vector <GraphNode*> adjacency_list;

public:

vector <GraphNode*> nodes; 

void addNode(string nodeVal); 

void addUDNodeEdge(GraphNode*first,GraphNode*second); 

void removeUDNodeEdge(GraphNode* first, GraphNode* second);

unordered_set<GraphNode*> getallNodes();

Graph* createRandomUnweightedGraphIter(int n);

Graph*createLinkedList(int n); 

}; 




void Graph::addNode(string nodeVal)
{
GraphNode*vertex = new GraphNode();
    vertex->val = nodeVal;
    Graph->nodes.push_back(vertex);
    //this->adjacency_list.push_back(vertex);
    //that adj means it connects to itslef,fix it. 
    //this->adj.push_back(vertex); 
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
   //for (int i = 0; i < adjacency_list.size(); ++i){
   // for( auto it = Graph->adjacency_list.begin(); it != Graph->adjacency_list.end(); ++it)
          // r_wing.insert(adjacency_list[i]); 
   //}
   for(int i = 0; i < Graphs->nodes.size(); ++i){
       for( auto it = Graphs->nodes->adj.begin(); it!= Graphs->nodes->adj.end(); ++it)
            r_wing.insert(it); 
   }
    return r_wing; 
}

void iterate_Graph(unordered_set<GraphNode*> graph){
    for( auto it = graph->adj.begin; it!= Graph->adj.end ++it)
    {
        cout  << " " << ": " << it->val;
    }
}

Graph*Graph:: createRandomUnweightedGraphIter(int n){
    for(int i = n; i > 0; i--){
        addNode(to_string(i)); 
   }
}

Graph*Graph:: createLinkedList(int n){
    unordered_set <GraphNode*> r_wing; 
    pair <GraphNode*, int> pair_one; 
    

    for(int i = n; i > 0; i--){
        Graph->addNode(to_string(i));
    }
    
    r_wing = getallNodes(); 
    
    for(int j = n; j > 0; j--){
        if(i > 0){
            addUDNodeEdge(r_wing.find(to_string(i)), r_wing.find(to_string(i+1))); 
        }
    }
}

vector GraphSearch::DFSRec(GraphNode* start, GraphNode* end){
    vector <GraphNode*> path; 
    vector <GraphNode*> temp; 
    bool FLAG = 0; 
    if(start == end){
        path.push_back(start); 
        return path; 
    }

    GraphSearch->visited.push_back(start); 
    //Starting at a random node, what is the first step? Examine its neighbors.
    for(auto it = start->adj.begin(); it != start->adj.end(); ++it){
        for(i = GraphSearch->visited.size(); i > 0; i--)
            if(it == GraphSearch->visited[i])
                FLAG = 1;
            if(FLAG == 1)
                continue;   
        temp = DFSRec(it, end);
        //If and only if the it is connected to end, push it back.
        if(temp != NULL){
            path.push_back(temp); 
            break; 
        }
    }
    return path; 
    //After this is called, make sure you set GraphSearch->visited to an empty list. 
}

vector<GraphNode*> GraphSearch::DFSIter(GraphNode* start, GraphNode* end){
    vector<GraphNode*> path; 
    stack <GraphNode*> tower; 
    GraphNode* v; 
    vector<GraphNode*> discovered; 
    tower.push(start);
    
    if(start == end){
        path.push_back(start);
        return path; 
    }
    while(!tower.empty()){
           v = tower.top(); 
           path.push_back(tower.pop());
           
           if(discovered[v]->visited == true)
                continue; 
        discovered[v]->visited = true; 
        for(auto it = v->adj.rbegin(); it!= v->adj.rend(); ++it)
        {
            GraphNode *u = *it;
            if(discovered[u] != true)
                tower.push(u); 
        }
    }
    return path; 
}

vector<GraphNode*> BFTRec(unordered_set<GraphNode*> graph){
    graph = getallNodes(); 
    vector<GraphNode*> full; 
    bool*visited = new bool[graph.size()]; 
    for(auto it = graph.begin(); it!= graph.end(); i++){
        if(visited[it] == false){
        visited[it] = true;
        full.push_back(it);  
        BFSRec(it->adj);
        }else 
            continue; 
    }
    return full;
}

vector<GraphNode*> BFTIter(unordered_set<GraphNode*> graph){
    graph = getallNodes(); 
    vector<GraphNode*> full; 
    bool*visited = new bool[graph.size()];
    for(auto it = graph.begin(); it != graph.end(); it++)
        visited[it] = false;

    deque <GraphNode*> q; 
    GraphNode* traverse; 

    for(auto it = graph.begin(); it!= graph.end(); ++it){
        if(visited[it] == false){
        visited[it] = true;
        q.push_back(it); 
        }
        else 
            continue; 
        vector<GraphNode*>::iterator i; 
        while(!q.empty()){
            traverse = q.front(); 
            cout << traverse << " ";
            full.push_back(traverse); 
            q.pop_front(); 

            for(i = traverse->adj.begin(); i!= traverse->adj.end(); ++i){
                if(!visited[*i])
                {
                    visited[*i] = true; 
                    q.push_back(*i); 
                }
            }  
        }
    }
return full; 
}

vector<GraphNode*> BFTLinkedListRec(unordered_set<GraphNode*> graph){
    unordered_set<GraphNode*> graph; 
    graph = getAllNodes(); 
    vector<GraphNode*> full; 
    bool*visited = new bool[graph.size]
    for(auto it = graph.begin(); it != graph.end(); it++)
    {
        visited[it] = true; 
        cout << "visited status : " << visited[it]; 
        full.push_back(it);
        BFTLinkedListRec(it->adj);
    }
    return full; 
}

vector<GraphNode*> BFTLinkedListIter(unordered_set<GraphNode*> graph){
    unordered_set<GraphNode*> graph; 
    graph = getAllNodes();
    vector<GraphNode*> full;
    for(it = graph.begin(); it!= graph.end(); it++){
        visited[it] = true; 
        cout << "visited status : " << visited[it]; 
        full.push_back(it); 
    }
    return full; 
}

int main(){
    Graph sector = new Graph(); 
    sector->createRandomUnweightedGraphIter(1000); 
    iterate_Graph(sector); 
    return 0; 
}