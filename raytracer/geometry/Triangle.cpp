#include "Triangle.hpp"
#include "../utilities/Ray.hpp"
#include "../utilities/Constants.hpp"
#include "../utilities/ShadeInfo.hpp"
#include "../utilities/BBox.hpp"

Triangle::Triangle() : v0(), v1(), v2()
{
}

Triangle::Triangle(const Point3D & a, const Point3D &b, const Point3D &c)
    : v0(a), v1(b), v2(c) 
{
    
}

Triangle::Triangle(const Triangle &object)
    : v0(object.v0), v1(object.v1), v2(object.v2)
{
}

Triangle &Triangle::operator=(const Triangle &rhs)
{
    this->v0 = rhs.v0;
    this->v1 = rhs.v1;
    this->v2 = rhs.v2;
    return *this;
}

std::string Triangle::to_string() const
{
    std::string tri_str = "Triangle:\n" + v0.to_string() + "\n" +
        v1.to_string() + "\n" + v2.to_string() + "\n";
    
    return tri_str;
}

bool Triangle::hit(const Ray &ray, float &t, ShadeInfo &sr) const
{
    // Reference: Ray tracing from the ground up (coursebook)

    float a = v0.x - v1.x, b = v0.x - v2.x, c = ray.d.x, d = v0.x - ray.o.x;
    float e = v0.y - v1.y, f = v0.y - v2.y, g = ray.d.y, h = v0.y - ray.o.y;
    float i = v0.z - v1.z, j = v0.z - v2.z, k = ray.d.z, l = v0.x - ray.o.z;

    float m = f * k - g * j, n = h * k - g * l, p = f * l - h * j; 
    float q = g * i - e * k, s = e * j - f * i;

    float inv_denom = 1.0 / (a * m + b * q + c * s);

    float e1 = d * m - b * n - c * p;
    float beta = e1 * inv_denom;

    if (beta < 0.0)
        return false;

    float r = e *l - h * i;
    float e2 = a * n + d * q + c * r;
    float gamma = e2 * inv_denom;

    if (gamma < 0.0)
        return false;

    if (beta + gamma > 1.0)
        return false;

    float e3 = a * p - b * r + d * s;
    float _t = e3 * inv_denom;

    if (_t < kEpsilon)
        return false;
    
    t = _t;
    sr.normal = (v1 - v0) ^ (v2-v0);
    sr.hit_point = ray.o + _t * ray.d;
    sr.hit = true;
    sr.ray = ray;
    sr.t = _t;
    sr.material_ptr = this->get_material();

    return true;

}

// TODO
BBox Triangle::getBBox() const
{
    BBox a;
    return a;
}