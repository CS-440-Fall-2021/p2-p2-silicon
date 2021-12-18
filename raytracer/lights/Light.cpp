#include "Light.hpp"

Light::Light() : shadows(false), ls(1.0), color(1.0)
{}

Light::Light(float ls, float color) : shadows(false), ls(ls), color(color)
{}

void Light::scale_radiance(float rad)
{
    ls = rad;
}

