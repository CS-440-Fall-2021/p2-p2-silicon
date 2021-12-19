#include "Phong.hpp"
#include "../world/World.hpp"
#include "../lights/Light.hpp"
#include "../lights/Ambient.hpp"
#include <iostream>

Phong::Phong() : ambient_brdf(new Lambertian), diffuse_brdf(new Lambertian),
    specular_brdf(new GlossySpecular)
{
}

void Phong::set_ka(float ka)
{
    ambient_brdf->set_kd(ka);
}

void Phong::set_kd(float kd)
{
    diffuse_brdf->set_kd(kd);
}
void Phong::set_cd(RGBColor cd)
{
    diffuse_brdf->set_cd(cd);
}
void Phong::set_ks(float ks)
{
    specular_brdf->set_cs(ks);
}

void Phong::set_exp(float exp)
{
    this->specular_brdf->set_exp(exp);
}

void Phong::set_sampler(Sampler *s)
{
    ambient_brdf->set_sampler(s);
    diffuse_brdf->set_sampler(s);
    specular_brdf->set_sampler(s);
}

void Phong::set_ambient(Lambertian* ambient)
{
    ambient_brdf = ambient;
}

void Phong::set_diffuse(Lambertian *diffuse)
{
    diffuse_brdf = diffuse;
}

void Phong::set_specular(GlossySpecular *specular)
{
    specular_brdf = specular;
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
        {
            L += (diffuse_brdf->f(s, wo, wi) +specular_brdf->f(s, wo, wi)) *s.w->lights[j]->L(s) * ndotwi;
        }
    }
    return (L);
}