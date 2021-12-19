#include "Point3D.hpp"
#include "Vector3D.hpp"
#include <math.h>
#include <iostream>

Point3D::Point3D() : x(0), y(0), z(0)
{
}

Point3D::Point3D(float c) : x(c), y(c), z(c)
{
}

Point3D::Point3D(float x, float y, float z) : x(x), y(y), z(z)
{
}

std::string Point3D::to_string() const
{
    std::string point = "Point3D: " + std::to_string(x) + ", "
        + std::to_string(y) + ", " + std::to_string(z);
    
    return point;
}

Point3D Point3D::operator-() const
{
    Point3D pt3d(*this);

    pt3d.x *= -1;
    pt3d.y *= -1;
    pt3d.z *= -1;

    return pt3d;
}

Vector3D Point3D::operator-(const Point3D &p) const
{
    Vector3D vec3D;
    vec3D.x = this->x - p.x;
    vec3D.y = this->y - p.y;
    vec3D.z = this->z - p.z;
    return vec3D;
}

Point3D Point3D::operator+(const Vector3D &v) const
{
    Point3D pt3d;
    pt3d.x = this->x + v.x;
    pt3d.y = this->y + v.y;
    pt3d.z = this->z + v.z;

    return pt3d;
}

Point3D Point3D::operator-(const Vector3D &v) const
{
    Point3D pt3d;
    pt3d.x = this->x - v.x;
    pt3d.y = this->y - v.y;
    pt3d.z = this->z - v.z;

    return pt3d;
}

bool Point3D::operator==(const Point3D &p) const
{
    if (x == p.x && y == p.y && z == p.z)
    {
        return true;
    }
    
    return false;
}

Point3D Point3D::operator*(const float s) const
{
    Point3D pt3d(*this);
    pt3d.x *= s; 
    pt3d.y *= s; 
    pt3d.z *= s;

    return pt3d; 
}

Point3D Point3D::operator-(const float s) const
{
    Point3D pt(*this);
    pt.x -= s;
    pt.y -= s;
    pt.z -= s;

    return pt;
}

float Point3D::d_squared(const Point3D &p) const
{
    float tmpx = (float) pow(p.x - x, 2);
    float tmpy = (float) pow(p.y - y, 2);
    float tmpz = (float) pow(p.z - z, 2);
    return tmpx+tmpy+tmpz;
}

float Point3D::distance(const Point3D &p) const
{
    return sqrt(this->d_squared(p));
}

Point3D operator*(const float a, const Point3D &pt)
{
    return pt * a;
}



Point3D min(const Point3D& a, const Point3D& b)
{
    return Point3D(std::min(a.x, b.x), std::min(a.y, b.y), std::min(a.z, b.z));
}

Point3D max(const Point3D& a, const Point3D& b)
{
    return Point3D(std::max(a.x, b.x), std::max(a.y, b.y), std::max(a.z, b.z));
}

// ! TESTING PURPOSES !

// int main(int argc, char const *argv[])
// {
//     Point3D* tst = new Point3D(1, 2, 3);
//     std::cout << tst->to_string() << std::endl;

//     return 0;
// }
