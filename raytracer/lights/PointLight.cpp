#include "PointLight.hpp"

PointLight::PointLight() : Light()
{}

Vector3D PointLight::get_direction(const ShadeInfo& src) const{
    return (location - src.hit_point);
}

RGBColor PointLight::L(const ShadeInfo& src) const{
    return (ls*color);
}