#include "Matte.hpp"
#include "../world/World.hpp"
#include "../lights/Light.hpp"

Matte::Matte() : Material(), ambient_brdf(new Lambertian), diffuse_brdf(new Lambertian)
{
}
void Matte::set_ka(const float k){
    ambient_brdf->set_kd(k);
}
void Matte::set_kd(const float k){
    diffuse_brdf->set_kd(k);
}
void Matte::set_cd(const RGBColor c){
    ambient_brdf->set_cd(c);
}
RGBColor Matte::shade(const ShadeInfo &sr) const{
    Vector3D wo = -sr.ray.d;
    RGBColor L = ambient_brdf->rho(sr, wo) * sr.w->ambient_ptr->L(sr);
    int numLights = sr.w->lights.size();
    for (int j = 0; j < numLights; j++) {
        Vector3D wi = sr.w->lights[j]->get_direction(sr);
        float ndotwi = sr.normal * wi;
        if (ndotwi > 0.0){
            L += diffuse_brdf->f(sr, wo, wi) * sr.w->lights[j]->L(sr) * ndotwi;
        }
    }
    return (L);
}
