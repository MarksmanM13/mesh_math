#include <iostream>
#include <unordered_map>
#include <string>
#include "helpers.h"

int main() {

    // creating an input list of triangles
    std::vector<Triangle> triangles = {{1.0, 3.0, 4.0},
                                       {1.0, 2.0, 4.0}, 
                                       {2.0, 4.0, 5.0}, 
                                       {3.0, 4.0, 6.0}, 
                                       {4.0, 6.0, 7.0}, 
                                       {4.0, 5.0, 7.0}};
    

    // starting the algorithm
    std::unordered_map<std::string, Triangle> known_edges;
    std::vector<Couple> couples;
    
    for (auto& triangle : triangles) {
        std::vector<Edge> edges = triangle.get_edges();

        for (auto& edge : edges) {
            auto edge_str = edge.make_hashable();
            
            // when we see an edge, hold onto it for when we see it again
            if (known_edges.find(edge_str) == known_edges.end()) {
                std::pair<std::string, Triangle> key_val_pair(edge_str, triangle);
                known_edges.insert(key_val_pair);
            }else {
                Couple c(triangle, known_edges.at(edge_str));
                couples.insert(couples.end(), c);
            }
        }      
    }

    // showing the found couple list
    for (auto& couple : couples) {
        std::cout << "Couple: " << couple.to_string() << std::endl;
    }
}

