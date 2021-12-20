#include "SpotLight.hpp"
#include "../utilities/ShadeInfo.hpp"

SpotLight::SpotLight() : PointLight()
{}

Vector3D SpotLight::get_direction(const ShadeInfo& src) const{
    Vector3D dir = (location - src.hit_point);
    dir.normalize();
    if (acos(direction * dir) <= theta) {
        return dir;
    }
    return direction;
}

RGBColor SpotLight::L(const ShadeInfo& src) const{
    return color;
}

void SpotLight::set_direction(const Vector3D& d){
    direction = Vector3D(d);
    direction.normalize();
}
void SpotLight::set_direction(float x, float y, float z){
    direction = Vector3D(x,y,z);
    direction.normalize();
}
void SpotLight::set_theta(float t){
    theta = t;
}