
#include "lop.hpp"
#include <sstream>

const size_t MAX_STATION_ID = 1000;

int main() 
{
    Graph graph;
    std::string line;
    size_t input_count = 0;


    while (std::getline(std::cin, line)) {
        std::istringstream iss(line);
        size_t from, to;
        double distance;
        char delim; // 区切り文字（カンマ）

        if (!(iss >> from >> delim >> to >> delim >> distance)) 
        {
            std::cerr << "Invalid input format." << std::endl;
            continue;
        } 
        if (from >= MAX_STATION_ID || to >= MAX_STATION_ID) // 駅番号が大きすぎる場合 マイナスの入力の場合も弾く
        {
            std::cerr << "Invalid input format." << std::endl;
            continue;
        }
        graph.addEdge(from, to, distance);
        input_count++;
    }
    // 最長経路の探索の処理
    graph.findLongestPath(graph, input_count);
    return 0;
}