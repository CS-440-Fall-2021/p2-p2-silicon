#include "grid.hpp"

Grid::Grid():Acceleration(){}

Grid::Grid(const Grid& G){}

Grid::Grid(vector<Geometry*>& G) {

// Initialization
    for (auto& geom: G) {
        bbox.extend(geom);
    }
    bbox.pmin; // min
    bbox.pmax; // max

    setup_cells(G);
}


void Grid::setup_cells(vector<Geometry*>& objects){

}