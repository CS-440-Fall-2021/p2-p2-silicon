#pragma once
#include "../utilities/RGBColor.hpp"

class World;
class Ray;

class Tracer
{
protected:
     World *w;

public:
    Tracer(World *world) {w = world;};
    virtual ~Tracer() = default;

    virtual RGBColor trace(const Ray &) const = 0;

    virtual RGBColor trace_ray(const Ray ray, const int depth) const =0;
    virtual RGBColor trace_ray(const Ray ray, float &tmin, const int depth) const =0;
};
