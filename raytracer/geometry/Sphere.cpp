#include "Sphere.hpp"
#include <iostream>
#include "../utilities/Vector3D.hpp"
#include "../utilities/Ray.hpp"
#include "../utilities/ShadeInfo.hpp"
#include "../utilities/Constants.hpp"
#include "../utilities/Bbox.hpp"

#include <math.h>

Sphere::Sphere() : c(), r(0)
{
}

Sphere::Sphere(const Point3D &center, float radius) : c(center), r(radius)
{
}

Sphere::Sphere(const Sphere &object) : c(object.c), r(object.r)
{
    this->set_material(object.get_material());
}

Sphere &Sphere::operator=(const Sphere &rhs)
{   
    this->c = rhs.c;
    this->r = rhs.r;
    this->set_material(rhs.get_material());

}

std::string Sphere::to_string() const
{
    std::string sphere_str = "Plane\n" + c.to_string() 
        + "\n" + std::to_string(r) + "\n";
    
    return sphere_str;
}

bool Sphere::hit(const Ray &ray, float &t,ShadeInfo &s) const
{
    float _t;
    Vector3D temp = ray.o - c;
    float a = ray.d * ray.d;
    float b = 2.0 * temp * ray.d;
    float c = temp * temp - r * r;
    float disc = b * b - 4.0 *a *c;

    if (disc < 0.0)
        return false;
    
    else
    {
        float e = sqrt(disc);
        float denom = 2.0 * a;
        _t = (-b - e) / denom; //smaller root

        if (_t > kEpsilon)
        {
            t = _t;
            s.normal = (temp + t * ray.d) / r;
            s.hit_point = ray.o + t * ray.d;
            s.hit = true;
            s.ray = ray;
            s.t = _t;
            s.material_ptr = this->get_material();

            return true;
        }
    }

    return false;

}

BBox Sphere::getBBox() const
{
    BBox a;
    return a;
}