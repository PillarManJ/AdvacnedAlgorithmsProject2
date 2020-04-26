#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <random>
#include <utility>
#include <cstdlib>
#include "GridGraph.h" 
#include "GridNode.h"


void GridGraph::addGridNode(final int x, final int y, final string val){
    GridNode vertex* = new GridNode();
        vertex->x_cord = x; 
        vertex->y_cord = y; 
        vertex->value = val; 
}

void GridGraph:: addUDGridNodeEdge(final GridNode first, final GridNode second){
    pair<GridNode*, int> pair_one; 
    pair_one.first = second; 
    pair_one.second = 1; 
    first->adj.insert(pair_one);

    pair<GridNode*, int> pair_two; 
    pair_two.first = first; 
    pair_two.second = 1; 
    second->adj.insert(pair_two); 
}

void GridGraph:: removeUDGridNodeEdge(final GridNode first, final GridNode second){
    first->adj.erase(second); 
    second->adj.erase(first); 
}

unordered_set<GridNode*> GridGraph::getallNodes(){
    unordered_set <GraphNode*> r_wing;
    for(int i = 0; i < adj.size(); ++i){
        for(auto it = GridGraph->adj.begin(); it!= Graph->adj.end() ++it)
            r_wing.insert(adj[i]); 
    }
    return r_wing; 
}

int randomNumberGen(){
    random rand = new random(); 
    rand = ((double) rand() / (RAND_MAX)) +1; 
    return rand; 
}

unordered_set CreateRandomGridGraph(int n){
    unordered_set<GridNode*> r_wing; 
    int x1 = x2 = y1 = y2 = 0;  
    int coinToss = 0; 
    for(int i = n; i > 0; --i){
        for(int j = i; j > 0; --j){
            x1 = r_wing[j]->x_cord;
            x2 = r_wing[j+1]->x_cord; 
            y1 = r_wing[j]->y_cord; 
            y2 = r_wing[j+1]->y_cord;
            addGridNode(i, j, to_string(n));  
            //check Vertical adjacents 
            if(abs(x2-x1) + abs(y2-y1)==1)
            coinToss = randomNumberGen(); 
            if(coinToss == 2)
                addUDGridNodeEdge(r_wing.find(to_string(j), r_wing.find(to_string(j+1))));
             
        }
        //check Horizontal adjacents
        x1 = r_wing[i]->x_cord; 
        x2 = r_wing[i+1]->x_cord; 
        y1 = r_wing[i]->y_cord; 
        y2 = r_wing[i+1]->y_cord;
        if(abs(x2- x1) + abs(y2-y1)==1)
        coinToss = randomNumberGen();
        if(coinToss == 2)
            addUDGridNodeEdge(r_wing.find(to_string[i], r_wing.find(to_string[i+1]))); 
    }
    return r_wing; 
}



int main(){
    return 0; 
}