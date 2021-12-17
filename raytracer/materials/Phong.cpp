#include "Phong.hpp"
#include "../world/World.hpp"
#include "../lights/Light.hpp"

Phong::Phong()
{
}
RGBColor Phong::shade(const ShadeInfo &s) const
{
    Vector3D wo = s.ray.d;
    RGBColor L = ambient_brdf->rho(s, wo) * s.w->ambient_ptr->L(s);
    int num_lights = s.w->lights.size();
    for (int j = 0; j < num_lights; j++)
    {
        Vector3D wi = s.w->lights[j]->get_direction(s);
        float ndotwi = s.normal * wi;
        if (ndotwi > 0.0)
            L += (diffuse_brdf->f(s, wo, wi) +specular_brdf->f(s, wo, wi)) *s.w->lights[j]->L(s) * ndotwi;
    }
    return (L);
}