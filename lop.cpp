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