#pragma once
#include <vector>

class Edge {
    public:
        float p1, p2;

        Edge(float p1, float p2) : p1{p1}, p2{p2} {};

        std::string make_hashable();
};

class Triangle {
    public:
        float x, y, z;

        Triangle(float x, float y, float z) : x{x}, y{y}, z{z} {};

        std::vector<Edge> get_edges();
        std::string to_string();
};

class Couple {
    public:
        Triangle t1, t2;

        Couple(Triangle t1, Triangle t2) : t1{t1}, t2{t2} {};

        std::string to_string();        
};

