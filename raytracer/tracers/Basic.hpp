#pragma once
#include "Tracer.hpp"


class Basic : public Tracer
{
private:
    /* data */
public:
    Basic(World *);
    virtual ~Basic() = default;

    virtual RGBColor trace(Ray const &) const override;
    virtual RGBColor trace_ray(const Ray ray, const int depth) const override;
    virtual RGBColor trace_ray(const Ray ray, float &tmin, const int depth) const override;
};
