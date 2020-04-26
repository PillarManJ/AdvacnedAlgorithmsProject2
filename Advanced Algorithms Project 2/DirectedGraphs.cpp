#include <iostream>
#include <unordered_set>
#include <random>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <utility>
#include "DirectedGraph.h"
#include "GraphNode.h"
#include "topSort.h"

void DirectedGraph::addNode(string value){
    GraphNode* vertex = new GraphNode(); 
    vertex->val = value; 
    this->adj.push_back(vertex);
}

void DirectedGraph ::addDEdge(GraphNode* first, GraphNode* second){
    pair<GraphNode* ,int> pair_one; 
    pair_one.first = second; 
    pair_one.second = 1; 
    first->adj.insert(pair_one); 
    //One direction only, B) 
}

void DirectedGraph::removeDEdge(GraphNode* first, GraphNode*second){
    first->adj.erase(second); 
    //One direction only, B) 
}

unordered_set<GraphNode*> DirectedGraph::getAllNodes(){
    unordered_set <GraphNode*> r_wing; 
    for(int i = 0; i < adj.size(); i++){
        for(auto it = DirectedGraph->adj.begin(); it!= DirectedGraph->adj.end(); ++it){
            r_wing.insert(adj[i]); 
        }
    }
    return r_wing; 
}


vector<GraphNode*> TopSort::Kahns(unordered_set<GraphNode*> first){
    vector<int> in_degree; 
    GraphNode*u;
    for(int u = 0; u < first.size(); u++){
        vector<GraphNode*> iterator itr;
        for(itr = first->adj.begin(); itr!= first->adj.end(); itr++)
            in_degree[*itr]++;  
    }

    queue<GraphNode*> q;
    for(int i = 0; i < first.size(); i++)
        if(in_degree[i] == 0)
            q.push(i); 

    int cnt = 0; 
    vector<GraphNode*> top_order; 
    while(!q.empty()){
        u = q.front(); 
        q.pop(); 
        top_order.push_back(u); 

        vector<GraphNode*>::iterator itr;
        for(itr = u->adj.begin(); itr!= u->adj.end(); itr++)
            if(in_degree[*itr] == 0)
                q.push(*itr); 
        cnt++; 
        if(cnt != first.size()){
            cout << "Uh ooooh, this is not a DAG because it has a cycle.";
            return; 
        }
    }
    return top_order; 
}

vector<GraphNode*> TopSort::mDFS(unordered_Set<GraphNode*> first){
    stack<GraphNode*> path;
    stack<GraphNode*> tower; 
    vector<GraphNode*> full_path; 
    GraphNode* v;
    GraphNode* u; 
    GraphNode* f;
    int count = 0; 
    vector<GraphNode*> discovered; 
    tower.push(first); 
     
    while(!tower.empty()){
        v = tower.top;
        count = 0; 
        tower.pop();
        
        discovered[v]->visited = true; 
        for(auto it = v->adj.rbegin(); it!= v->adj.rend(); ++it)
        {
            u = *it; 
            discovered.push_back(u);
            if(discovered[u]->visited != true){
                tower.push(u); 
                discovered[u]->visited = true; 
            }
            if(discovered.size() == v->adj.size()){
                path.push(v);
                discovered.clear(); 
            }
        }       
    } 
  for(auto it = path.rbegin(); it!= path.rend(); ++it){
      full_path.push_back(path.pop());
  }  
  return full_path;
}

DirectedGraph *DirectedGraph::createRandomDAGIter(int n){
    unordered_set <GraphNode*> r_wing; 
    vector<GraphNode*> kahns; 
    vector<GraphNode*> mDFS;

    for(int i = 0; i < n; i++)
    addNode(to_string(i));
    
    r_wing = getAllNodes(); 
    for(int j = 0; j < n; j++){
        if(i > 0)
            addDEdge(r_wing.find(to_string[i]), r_wing.find(to_string[i]));
            r_wing.find(to_string[i])->adj = r_wing.find(to_string[i]);  
    }
    kahns = Kahns(r_wing); 
    mDFS = mDFS(r_wing); 
}

int main(){

return 0; 
}