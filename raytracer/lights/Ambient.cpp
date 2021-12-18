#include "Ambient.hpp"
#include"../utilities/Vector3D.hpp"

Ambient::Ambient() : Light()
{}

Ambient::Ambient(float _ls, float _c) : Light(_ls, _c)
{}

Vector3D Ambient::get_direction(const ShadeInfo& src) const{
    return Vector3D(0.0);
}

RGBColor Ambient::L(const ShadeInfo& src) const{
    return (ls*color);
}