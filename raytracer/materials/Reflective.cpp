#include "Reflective.hpp"
#include "../world/World.hpp"
#include "../tracers/Tracer.hpp"
#include "../BRDF/PerfectSpecular.hpp"

Reflective::Reflective() : Phong(), reflective_brdf(new PerfectSpecular)
{}

void Reflective::set_kr(float kr)
{
    reflective_brdf->set_kr(kr);
}

void Reflective::set_cr(RGBColor c)
{
    reflective_brdf->set_cr(c);
}

void Reflective::set_reflective_brdf(PerfectSpecular *perf)
{
    reflective_brdf = perf;
}

RGBColor Reflective::shade(const ShadeInfo &s) const
{
    RGBColor L(Phong::shade(s)); // direct illumination
    Vector3D wo = -s.ray.d;
    Vector3D wi;
    RGBColor fr = reflective_brdf->sample_f(s, wo, wi);
    Ray reflected_ray(s.hit_point, wi);
    L += fr * s.w->tracer_ptr->trace_ray(reflected_ray, s.depth + 1) *
         (s.normal * wi);
    return (L);
}