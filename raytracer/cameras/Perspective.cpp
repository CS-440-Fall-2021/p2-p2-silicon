#include "Perspective.hpp"
#include "../utilities/Vector3D.hpp"

Perspective::Perspective() : pos(0)
{}

Perspective::Perspective(float c) : pos(c)
{}

Perspective::Perspective(float x, float y, float z) : pos(x,y,z)
{}

Perspective::Perspective(const Point3D &pt) : pos(pt.x,pt.y,pt.z)
{}

Perspective& Perspective::operator=(const Perspective &other){
    pos.x = other.pos.x;
    pos.y = other.pos.y;
    pos.z = other.pos.z;
    return *this;
}

Vector3D Perspective::get_direction(const Point3D &p) const{
   Vector3D x = p - pos;
    x.normalize();
   return x;
}