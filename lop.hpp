#ifndef LOP_HPP
#define LOP_HPP


#include <iostream>
#include <string>
#include <vector>
#include <map>

struct Edge 
{
    int to; //どこに向かうか
    double distance;  //距離
};

class Graph
{
    private :
        std::map<int, std::vector<Edge> > graph_;
    public :
        void addEdge(int from, int to, double distance); //辺の追加
        const std::vector<Edge>& getEdges(int from) const; //辺の取得
        void allview(void);
        void dfs(const Graph& graph, int node, std::vector<bool>& visited, std::vector<int>& path, std::vector<int>& longestPath, double& maxLength, double currentLength);
        void findLongestPath(const Graph& graph, int numNodes);
};


#endif