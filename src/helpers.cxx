#include <vector>
#include <string>
#include "helpers.h"

std::vector<Edge> Triangle::get_edges() {
    Edge e1 = {this->x, this->y};
    Edge e2 = {this->y, this->z};
    Edge e3 = {this->x, this->z};

    return {e1, e2, e3};
}

std::string Triangle::to_string() {
    return std::to_string(this->x) + "," + std::to_string(this->y) + "," + std::to_string(this->z);
}


std::string Edge::make_hashable() {
    return std::to_string(this->p1) + "-" + std::to_string(this->p2);
}

std::string Couple::to_string() {
    return t1.to_string() + " : " + t2.to_string();
}
