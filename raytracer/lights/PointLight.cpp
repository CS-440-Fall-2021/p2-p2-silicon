#include "PointLight.hpp"

PointLight::PointLight() : Light(), location(Vector3D())
{}


void PointLight::set_location(float _x, float _y, float _z)
{
    location = Vector3D(_x, _y, _z);
}

Vector3D PointLight::get_direction(const ShadeInfo& src) const{
    return (location - src.hit_point);
}

RGBColor PointLight::L(const ShadeInfo& src) const{
    return (ls*color);
}