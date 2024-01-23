
#include "lop.hpp"
#include <sstream>

int main() 
{
    Graph graph;
    std::string line;

    while (std::getline(std::cin, line)) {
        std::istringstream iss(line);
        int from, to;
        double distance;
        char delim; // 区切り文字（カンマ）

        if (!(iss >> from >> delim >> to >> delim >> distance)) {
            // パースエラーの処理
            std::cerr << "Invalid input format." << std::endl;
            continue;
        } 
        graph.addEdge(from, to, distance);
    }

    graph.allview();


    // 最長経路の探索など、その他の処理
    return 0;
}