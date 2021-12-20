#include "Lambertian.hpp"
#include "../utilities/Constants.hpp"

Lambertian::Lambertian() : BRDF(), kd(1.0), cd(RGBColor(0.0))
{
}
Lambertian::Lambertian(Sampler *s) : BRDF(s)
{
}


void Lambertian::set_kd(float kd){
    this->kd = kd;
}
void Lambertian::set_cd(RGBColor cd){
    this->cd = cd;
}
float Lambertian::get_kd(){
    return kd;
}
RGBColor Lambertian::get_cd(){
    return cd;
}

RGBColor Lambertian::f(const ShadeInfo& sr, const Vector3D& wi, const Vector3D& wo) const{
    return (kd*cd*invPI);
}

RGBColor Lambertian::sample_f(const ShadeInfo& sr, Vector3D& wi, const Vector3D& wo) const{
    return black;
}
RGBColor Lambertian::sample_f(const ShadeInfo& sr, Vector3D& wi, const Vector3D& wo, float& pdf) const{
    // Vector3D w = sr.normal;
    // Vector3D v(0.0034, 1.0, 0.0071);
    // v = v ^ w;
    // v.normalize();
    // Vector3D u = v ^ w;
    // Point3D sp = sampler_ptr->sample_hemisphere();
    // wi = sp.x * u + sp.y * v + sp.z * w;
    // wi.normalize();
    // pdf = sr.normal * wi * invPI;

    // return (kd * cd * invPI);
    return black;
}

RGBColor Lambertian::rho(const ShadeInfo& sr, const Vector3D& wo) const{
    return (kd*cd);
}