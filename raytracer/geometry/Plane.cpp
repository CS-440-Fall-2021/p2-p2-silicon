#include "Plane.hpp"
#include <iostream>
#include "../utilities/BBox.hpp"
#include "../utilities/Ray.hpp"
#include "../utilities/ShadeInfo.hpp"
#include "../utilities/Constants.hpp"

Plane::Plane()
{
    a.x = 0;
    a.y = 0;
    a.z = 0;

    n.x = 0;
    n.y = 1;
    n.z = 0;
}

Plane::Plane(const Point3D &pt, const Vector3D &_n)
    : a(pt), n(_n)
{
    n.normalize();
}

Plane::Plane(const Plane &object) : a(object.a), n(object.n)
{
}


BBox Plane::getBBox() const{
    BBox bounding_box;
    return bounding_box;
}

Plane &Plane::operator=(const Plane &rhs)
{
    this->a = rhs.a;
    this->n = rhs.n;

    return *this;
}

std::string Plane::to_string() const
{
    std::string plane_str = "Plane\n" + a.to_string() 
        + "\n" + n.to_string() + "\n";

    return plane_str;
}

bool Plane::hit(const Ray &ray, float &t, ShadeInfo &s) const
{
    // Get ray parameter t
    double _t = (this->a - ray.o) * this->n / (ray.d * this->n);

    // Ray hits plane only once
    if(_t > kEpsilon)
    {
        t = _t;
        s.t = _t;
        s.normal = n;
        s.ray = ray;
        s.hit_point = ray.o + _t * ray.d;
        s.material_ptr = this->get_material();
        s.hit = true;

        return true;
    }

    return false;
    
}