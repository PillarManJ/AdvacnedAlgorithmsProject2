#include <iostream>
#include <string>
#include <unordered_set> 
#include <unordered_map>
#include <utility>

template <class T>
class WeightedGraph{
    vector<T> visited; 



    public: 
        unordered_set<T> nodes; 
        unordered_set<T> edges; 
        void addNode(final T);
        void addWeightedEdge(final T, final T, final T);
        void removeDirectedEdge(final T, final T); 
        unordered_set<T> getAllNodes(); 
        unordered_set<T> getAllEdges();
        WeightedGraph* createRandomWeightedGraph(T n);
        WeightedGraph* createLinkedList(T n);  
        unordered_map<T>djkstras(T n); 
}