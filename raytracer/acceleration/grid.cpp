#include "grid.hpp"
Grid::Grid():Acceleration(){}

Grid::Grid(const Grid& G){}

Grid::Grid(vector<Geometry*>& G) {	
	for (int i = 0; i < G.size(); i++) {
		this->objects.push_back(G[i]);
	}
}

float clamp(float a,float low, float high) {
	return a > high ? high : a < low ? low : a;
}

// The functions hit and setup_cells for the acceleration structure, Regular Grids, is created using the book (Ray Tracing From The Ground Up) website

bool Grid::hit(const Ray& R, float& t, ShadeInfo& SI) const{
	double ox = R.o.x;
	double oy = R.o.y;
	double oz = R.o.z;

	double dx = R.d.x;
	double dy = R.d.y;
	double dz = R.d.z;

	double x0 = bbox.pmin.x;
	double y0 = bbox.pmin.y;
	double z0 = bbox.pmin.z;

	double x1 = bbox.pmax.x;
	double y1 = bbox.pmax.y;
	double z1 = bbox.pmax.z;
	
	double tx_min, ty_min, tz_min;
	double tx_max, ty_max, tz_max; 
	
	// the following code includes modifications from Shirley and Morley (2003)
	
	double a = 1.0 / dx;
	if (a >= 0) {
		tx_min = (x0 - ox) * a;
		tx_max = (x1 - ox) * a;
	}
	else {
		tx_min = (x1 - ox) * a;
		tx_max = (x0 - ox) * a;
	}
	
	double b = 1.0 / dy;
	if (b >= 0) {
		ty_min = (y0 - oy) * b;
		ty_max = (y1 - oy) * b;
	}
	else {
		ty_min = (y1 - oy) * b;
		ty_max = (y0 - oy) * b;
	}
	
	double c = 1.0 / dz;
	if (c >= 0) {
		tz_min = (z0 - oz) * c;
		tz_max = (z1 - oz) * c;
	}
	else {
		tz_min = (z1 - oz) * c;
		tz_max = (z0 - oz) * c;
	}
	
	double t0, t1;
	
	if (tx_min > ty_min)
		t0 = tx_min;
	else
		t0 = ty_min;
		
	if (tz_min > t0)
		t0 = tz_min;
		
	if (tx_max < ty_max)
		t1 = tx_max;
	else
		t1 = ty_max;
		
	if (tz_max < t1)
		t1 = tz_max;
			
	if (t0 > t1)
		return(false);
	
			
	// initial cell coordinates
	
	int ix, iy, iz;
	bbox.contains(R.o);
	if (bbox.contains(R.o)) {  			// does the ray start inside the grid?	
		ix = clamp((ox - x0) * nx / (x1 - x0), 0, nx - 1);
		iy = clamp((oy - y0) * ny / (y1 - y0), 0, ny - 1);
		iz = clamp((oz - z0) * nz / (z1 - z0), 0, nz - 1);
	}
	else {
		Point3D p = R.o + t0 * R.d;  // initial hit point with grid's bounding box
		ix = clamp((p.x - x0) * nx / (x1 - x0), 0, nx - 1);
		iy = clamp((p.y - y0) * ny / (y1 - y0), 0, ny - 1);
		iz = clamp((p.z - z0) * nz / (z1 - z0), 0, nz - 1);
	}
	
	// ray parameter increments per cell in the x, y, and z directions
	
	double dtx = (tx_max - tx_min) / nx;
	double dty = (ty_max - ty_min) / ny;
	double dtz = (tz_max - tz_min) / nz;
		
	double 	tx_next, ty_next, tz_next;
	int 	ix_step, iy_step, iz_step;
	int 	ix_stop, iy_stop, iz_stop;
	
	if (dx > 0) {
		tx_next = tx_min + (ix + 1) * dtx;
		ix_step = +1;
		ix_stop = nx;
	}
	else {
		tx_next = tx_min + (nx - ix) * dtx;
		ix_step = -1;
		ix_stop = -1;
	}
	
	if (dx == 0.0) {
		tx_next = kHugeValue;
		ix_step = -1;
		ix_stop = -1;
	}
	
	
	if (dy > 0) {
		ty_next = ty_min + (iy + 1) * dty;
		iy_step = +1;
		iy_stop = ny;
	}
	else {
		ty_next = ty_min + (ny - iy) * dty;
		iy_step = -1;
		iy_stop = -1;
	}
	
	if (dy == 0.0) {
		ty_next = kHugeValue;
		iy_step = -1;
		iy_stop = -1;
	}
		
	if (dz > 0) {
		tz_next = tz_min + (iz + 1) * dtz;
		iz_step = +1;
		iz_stop = nz;
	}
	else {
		tz_next = tz_min + (nz - iz) * dtz;
		iz_step = -1;
		iz_stop = -1;
	}
	
	if (dz == 0.0) {
		tz_next = kHugeValue;
		iz_step = -1;
		iz_stop = -1;
	}
	
		
	// traverse the grid
	
	while (true) {	
		Geometry* object_ptr = cells[ix + nx * iy + nx * ny * iz];
		
		if (tx_next < ty_next && tx_next < tz_next) {
			if (object_ptr && object_ptr->hit(R, t, SI) && t < tx_next) {
				return (true);
			}
			
			tx_next += dtx;
			ix += ix_step;
						
			if (ix == ix_stop)
				return (false);
		} 
		else { 	
			if (ty_next < tz_next) {
				if (object_ptr && object_ptr->hit(R, t,SI) && t < ty_next) {
					return (true);
				}
				
				ty_next += dty;
				iy += iy_step;
								
				if (iy == iy_stop)
					return (false);
		 	}
		 	else {		
				if (object_ptr && object_ptr->hit(R, t, SI) && t < tz_next) {
					return (true);
				}
				
				tz_next += dtz;
				iz += iz_step;
								
				if (iz == iz_stop)
					return (false);
		 	}
		}
	}
}


// find the minimum grid coordinates, based on the bounding boxes of all the object
Point3D Grid::find_min_bounds() {
	Point3D p0(kHugeValue);

	for (auto& object: objects) {
		object->getBBox().pmin.x < p0.x ? p0.x = object->getBBox().pmin.x : p0.x;
		object->getBBox().pmin.y < p0.y ? p0.y = object->getBBox().pmin.y : p0.y;
		object->getBBox().pmin.z < p0.z ? p0.z = object->getBBox().pmin.z : p0.z;
	}

	p0.x -= kEpsilon; p0.y -= kEpsilon;	p0.z -= kEpsilon;
	return (p0);
}

//------------------------------------------------------------------ find_max_bounds

// find the maximum grid coordinates, based on the bounding boxes of the objects
//DONE
Point3D Grid::find_max_bounds() {
	Point3D p1(-kHugeValue);

	for (auto& object: objects) {
		object->getBBox().pmax.x > p1.x ? p1.x = object->getBBox().pmax.x : p1.x;
		object->getBBox().pmax.y > p1.y ? p1.y = object->getBBox().pmax.y : p1.y;
		object->getBBox().pmax.z > p1.z ? p1.z = object->getBBox().pmax.z : p1.z;
	}
    
	p1.x += kEpsilon; p1.y += kEpsilon;	p1.z += kEpsilon;	
	return (p1);
}


void Grid::setup_cells(vector<Geometry*>& objects){
    Point3D p0 = find_min_bounds();
	Point3D p1 = find_max_bounds();
	
	this->bbox.pmin.x = p0.x;
	this->bbox.pmin.y = p0.y;
	this->bbox.pmin.z = p0.z;

	this->bbox.pmax.x = p1.x;
	this->bbox.pmax.y = p1.y;
	this->bbox.pmax.z = p1.z;
		
	// compute the number of grid cells in the x, y, and z directions
	
	int numObjects = objects.size();

	// multiplyer scales the number of grid cells relative to the number of objects
	const double multiplier = 2.0; 
	const double cubeRoot = 0.3333333333333333333333;
	// dimensions of the grid in the x, y, and z directions
	double wx = p1.x - p0.x;
	double wy = p1.y - p0.y;
	double wz = p1.z - p0.z;  
	
	double s = pow(wx * wy * wz / numObjects, cubeRoot);    

	nx = multiplier * wx / s + 1;
	ny = multiplier * wy / s + 1;
	nz = multiplier * wz / s + 1;
	// set up the array of grid cells with null pointers
	
	int num_cells = nx * ny * nz;
	this->cells.reserve(numObjects);
	for (int j = 0; j < num_cells; j++)
		this->cells.push_back(NULL);
	// set up a temporary array to hold the number of objects stored in each cell
	vector<int> counts;
	counts.reserve(num_cells);
	for (int j = 0; j < num_cells; j++)
		counts.push_back(0);
		

	// put the objects into the cells
	BBox obj_bBox; 	// object's bounding box
	int index;  	// cell's array index
			
	for (int j = 0; j < numObjects; j++) {
		obj_bBox =  objects[j]->getBBox();
		// compute the cell indices at the corners of the bounding box of the object
		int ixmin = clamp((obj_bBox.pmin.x - p0.x) * nx / (p1.x - p0.x), 0, nx - 1);
		int iymin = clamp((obj_bBox.pmin.y - p0.y) * ny / (p1.y - p0.y), 0, ny - 1);
		int izmin = clamp((obj_bBox.pmin.z - p0.z) * nz / (p1.z - p0.z), 0, nz - 1);
		int ixmax = clamp((obj_bBox.pmax.x - p0.x) * nx / (p1.x - p0.x), 0, nx - 1);
		int iymax = clamp((obj_bBox.pmax.y - p0.y) * ny / (p1.y - p0.y), 0, ny - 1);
		int izmax = clamp((obj_bBox.pmax.z - p0.z) * nz / (p1.z - p0.z), 0, nz - 1);
				
		// add the object to the cells
		for (int iz = izmin; iz <= izmax; iz++) 					// cells in z direction
			for (int iy = iymin; iy <= iymax; iy++)					// cells in y direction
				for (int ix = ixmin; ix <= ixmax; ix++) {			// cells in x direction
					index = ix + nx * iy + nx * ny * iz;
															
					if (counts[index] == 0) {
						cells[index] = objects[j];
						counts[index] += 1;  						// now = 1
					}
					else {
						if (counts[index] == 1) {
							Compound* compound_ptr = new Compound;	// construct a compound object
							compound_ptr->add_object(cells[index]); // add object already in cell
							compound_ptr->add_object(objects[j]);  	// add the new object
							cells[index] = compound_ptr;			// store compound in current cell
							counts[index] += 1;  					// now = 2
						}						
						else {										// counts[index] > 1
							cells[index]->add_object(objects[j]);	// just add current object
							counts[index] += 1;						// for statistics only
						}
					}
				}	
	}  // end of for (int j = 0; j < numObjects; j++)
	
	// erase the Compound::vector that stores the object pointers, but don't delete the objects
	
	objects.erase (objects.begin(), objects.end());
}