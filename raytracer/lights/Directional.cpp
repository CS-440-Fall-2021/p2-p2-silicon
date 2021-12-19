#include "Directional.hpp"

Directional::Directional() : Light()
{}

Vector3D Directional::get_direction(const ShadeInfo& src) const{
    return direction;
}

RGBColor Directional::L(const ShadeInfo& src) const{
    return color;
}

void Directional::set_direction(const Vector3D& d){
    direction = Vector3D(d);
    direction.normalize();
}
void Directional::set_direction(float x, float y, float z){
    direction = Vector3D(x,y,z);
    direction.normalize();
}