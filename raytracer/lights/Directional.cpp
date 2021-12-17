#include "Directional.hpp"

Directional::Directional() : Light()
{}

Vector3D Directional::get_direction(const ShadeInfo& src) const{
    return direction;
}

RGBColor Directional::L(const ShadeInfo& src) const{
    return color;
}