#pragma once
#include "../utilities/RGBColor.hpp"
#include "../utilities/Ray.hpp"

class World;

class Tracer
{
protected:
     World *w;

public:
    Tracer(World *world) {w = world;};
    virtual ~Tracer() = default;

    virtual RGBColor trace_ray(const Ray ray, const int depth) const = 0;
    virtual RGBColor trace_ray(const Ray ray, float &tmin, const int depth) const 
    {return RGBColor();}
};
