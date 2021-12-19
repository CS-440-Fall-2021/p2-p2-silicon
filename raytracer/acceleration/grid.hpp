#include <iostream>
#include <vector>
#include <math.h>

#include "../utilities/ShadeInfo.hpp"
#include "../utilities/BBox.hpp"
#include "../utilities/Point3D.hpp"

#include "acceleration.hpp"
#include "../geometry/Compound.hpp"

using namespace std;

class Grid: public Acceleration{
    private:
        vector<Geometry*> objects;
        vector<Geometry*> cells;
        int nx,ny,nz;
        BBox bbox;
    public:
        Grid();
        Grid(const Grid& G);
        Grid(vector<Geometry*>& G);
        
        // pre-req for setup_cells
        Point3D find_max_bounds();
        Point3D find_min_bounds();

        virtual bool hit(const Ray& R, float& t, ShadeInfo& SI) const;
        
        void setup_cells(vector<Geometry*>& objects);
};