#pragma once
#include "Tracer.hpp"

class Whitted : public Tracer
{
private:
    /* data */
public:
    Whitted(World *world);
    ~Whitted() = default;

    virtual RGBColor trace_ray(const Ray ray, const int depth) const override;
};