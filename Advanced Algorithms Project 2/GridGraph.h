#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>  

template <class T> 
class GridGraph{
    public: 
        void addGridNode(final int x, final int y, final string nodeVal);
        void addUDGridNodeEdge(final T first, final T second); 
        void removeUDGridNodeEdge(final T first, final T second); 
        unordered_set <T> getAllNodes(); 
};