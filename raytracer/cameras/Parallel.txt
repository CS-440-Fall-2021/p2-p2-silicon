#include "Parallel.hpp"

Parallel::Parallel() : dir(0,0,-1)
{}

Parallel::Parallel(float c) : dir(c,c,c)
{}

Parallel::Parallel(float x, float y, float z) : dir(x,y,z)
{}

Parallel::Parallel(const Vector3D &d) : dir(d.x,d.y,d.z)
{}

Parallel& Parallel::operator=(const Parallel &other){
    dir.x = other.dir.x;
    dir.y = other.dir.y;
    dir.z = other.dir.z;
    return *this;
}


Vector3D Parallel::get_direction(const Point3D &p) const{
    return dir;
}