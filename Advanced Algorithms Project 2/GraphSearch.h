#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <iostream>
#include <string>
#include <utility> 


template <class T>
class GraphSearch {

    vector<T> visited; 
public: 
    vector <T> DFSRec(T start, T end); 
    vector <T> DFSIter(T start, T end); 
    vector <T> BFTRec(Graph);
    vector <T> BFTIter(Graph); 
}; 

