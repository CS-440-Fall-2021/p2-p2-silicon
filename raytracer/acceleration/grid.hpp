#pragma once

#include <vector>

#include "../utilities/ShadeInfo.hpp"
#include "../geometry/Compound.hpp"
#include "../utilities/BBox.hpp"
#include "acceleration.hpp"

class Grid: public Acceleration{
    public:
        Grid();
        Grid(const Grid& G);
        Grid(vector<Geometry*>& G);
        void setup_cells(vector<Geometry*>& objects);
        virtual bool hit(const Ray& R, float& t, ShadeInfo& SI);
    private:
        vector<Geometry*> cells;
        int nx,ny,nz;
        BBox bbox;
        
};