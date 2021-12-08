#include "Ray.hpp"

Ray::Ray() : o(), d(), w(1)
{
}

Ray::Ray(const Point3D &origin, const Vector3D &dir) : o(origin), d(dir), w(1)
{
    d.normalize();
}

std::string Ray::to_string() const
{
    std::string ray = "Ray: \n" + o.to_string() + "\n" + d.to_string() + "\nWeightage: " + std::to_string(w) + "\n";

    return ray;
}