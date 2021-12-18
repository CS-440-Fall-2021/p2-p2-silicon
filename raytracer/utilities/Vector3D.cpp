#include "Point3D.hpp"
#include "Vector3D.hpp"
#include <math.h>
#include <iostream>

Vector3D::Vector3D() : x(0), y(0), z(0)
{
}

Vector3D::Vector3D(double c) : x(c), y(c), z(c)
{
}

Vector3D::Vector3D(double _x, double _y, double _z) : x(_x), y(_y), z(_z)
{
}

Vector3D::Vector3D(const Point3D &p) : x(p.x), y(p.y), z(p.z)
{
}

Vector3D &Vector3D::operator=(const Point3D &rhs)
{
    this->x = rhs.x;
    this->y = rhs.y;
    this->z = rhs.z;

    return *this;
}

std::string Vector3D::to_string() const
{
    std::string vec = "Vector3D: " + std::to_string(x) + ", "
        + std::to_string(y) + ", " + std::to_string(z);
    
    return vec;
}

Vector3D Vector3D::operator-() const
{
    Vector3D vec3d(*this);

    vec3d.x *= -1;
    vec3d.y *= -1;
    vec3d.z *= -1;

    return vec3d;
}

Vector3D Vector3D::operator+(const Vector3D &v) const
{
    Vector3D vec3D;
    vec3D.x = this->x + v.x;
    vec3D.y = this->y + v.y;
    vec3D.z = this->z + v.z;
    return vec3D;
}

Vector3D &Vector3D::operator+=(const Vector3D &v)
{
    this->x += v.x;
    this->y += v.y;
    this->z += v.z;
    return *this;
}

Vector3D Vector3D::operator-(const Vector3D &v) const
{
    Vector3D vec3D;
    vec3D.x = this->x - v.x;
    vec3D.y = this->y - v.y;
    vec3D.z = this->z - v.z;
    return vec3D;
}

Vector3D &Vector3D::operator-=(const Vector3D &v)
{
    this->x -= v.x;
    this->y -= v.y;
    this->z -= v.z;
    return *this;
}

bool Vector3D::operator==(const Vector3D &v) const
{
    if (x == v.x && y == v.y && z == v.z)
    {
        return true;
    }
    
    return false;
}

Vector3D Vector3D::operator*(const double s) const
{
    Vector3D vec3d(*this);
    vec3d.x *= s; 
    vec3d.y *= s; 
    vec3d.z *= s;

    return vec3d; 
}

Vector3D Vector3D::operator/(const double s) const
{
    Vector3D vec3d(*this);
    vec3d.x /= s; 
    vec3d.y /= s; 
    vec3d.z /= s;

    return vec3d; 
}

void Vector3D::normalize()
{
    double len = this->length();

    this->x /= len;
    this->y /= len;
    this->z /= len;

    return;
}

double Vector3D::len_squared() const
{
    double tmpx = pow(x, 2);
    double tmpy = pow(y, 2);
    double tmpz = pow(z, 2);
    return tmpx+tmpy+tmpz;
}

double Vector3D::length() const
{
    return sqrt(this->len_squared());
}

double Vector3D::operator*(const Vector3D &b) const
{
    return this->x * b.x + this->y * b.y + this->z * b.z;
}


Vector3D Vector3D::operator^(const Vector3D &v) const
{
    Vector3D vec3d;
    vec3d.x = y * v.z - z * v.y;
    vec3d.y = z * v.x - x * v.z;
    vec3d.z = x * v.y - y * v.x;

    return vec3d;
}

Vector3D operator*(const double a, const Vector3D &v)
{
    return v * a;
}

// ! TESTING PURPOSES !

// int main(int argc, char const *argv[])
// {
//     Vector3D tst(3, -5, 4);
//     Vector3D tst2(2, 6, 5);

//     std::cout << (tst*tst2) << std::endl;
//     std::cout << (tst^tst2).to_string() << std::endl;

//     return 0;
// }