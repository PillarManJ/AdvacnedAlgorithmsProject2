#include <iostream>
#include <string>
#include <unordered_map>

class GridNode{
    public: 
    int x_cord = NULL; 
    int y_cord = NULL; 
    string value = ""; 
    vector <GridNode*> adj; 
};