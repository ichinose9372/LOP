#include "lop.hpp"

void Graph::addEdge(int from, int to, double distance) 
{
    Edge edge;
    edge.to = to;
    edge.distance = distance;
    graph_[from].push_back(edge);
}

const std::vector<Edge>& Graph::getEdges(int from) const 
{
    static const std::vector<Edge> empty;
    std::map<int, std::vector<Edge> >::const_iterator it = graph_.find(from);
    if (it != graph_.end()) 
        return it->second;
    else
        return empty;
}

void Graph::allview(void)
{
    std::map<int, std::vector<Edge> >::iterator it = graph_.begin();
    while(it != graph_.end())
    {
        
        std::vector<Edge>::iterator it2 = it->second.begin();
        while(it2 != it->second.end())
        {
            std::cout << it->first << " : " << it2->to << " " << it2->distance << " \n";
            it2++;
        }
        std::cout << std::endl;
        it++;
    }
}



void Graph::dfs(const Graph& graph, int node, std::vector<bool>& visited, std::vector<int>& path, std::vector<int>& longestPath, double& maxLength, double currentLength) 
{
    visited[node] = true;
    path.push_back(node);

    if (currentLength > maxLength) {
        maxLength = currentLength;
        longestPath = path;
    }
    
    const std::vector<Edge>& edges = graph.getEdges(node);
    for (size_t i = 0; i < edges.size(); ++i) 
    {
        const Edge& edge = edges[i];
        if (!visited[edge.to]) 
        {
            dfs(graph, edge.to, visited, path, longestPath, maxLength, currentLength + edge.distance);
        }
    }
    path.pop_back();
    visited[node] = false;
}

void Graph::findLongestPath(const Graph& graph, int numNodes) {
    std::vector<bool> visited(numNodes, false);
    std::vector<int> path;
    std::vector<int> longestPath;

    double maxLength = 0;

    for (int i = 0; i < numNodes; i++) 
    {
        dfs(graph, i, visited, path, longestPath, maxLength, 0);
    }

    std::cout << std::endl;
    for (size_t i = 0; i < longestPath.size(); ++i) 
    {
        std::cout << longestPath[i] << "\n";
    }
}