#include"PerfectSpecular.hpp"
#include"../utilities/Constants.hpp"
#include <math.h>
#include <math.h>

PerfectSpecular::PerfectSpecular() : BRDF(), kr(0.0), cr(1.0)
{
}

PerfectSpecular::PerfectSpecular(Sampler *s) : BRDF(s), kr(0.0), cr(1.0)
{
}

void PerfectSpecular::set_kr(float kr){
    this->kr = kr;
}
void PerfectSpecular::set_cr(RGBColor cd){
    this->cr = cd;
}
float PerfectSpecular::get_kr(){
    return kr;
}
RGBColor PerfectSpecular::get_cr(){
    return cr;
}

RGBColor PerfectSpecular::f(const ShadeInfo& sr, const Vector3D& wi, const Vector3D& wo) const{
    return black;
}

RGBColor PerfectSpecular::sample_f(const ShadeInfo& sr, Vector3D& wi, const Vector3D& wo) const{
    float ndotwo = sr.normal * wo;
    wi = -wo + 2.0 * sr.normal * ndotwo;
    return (kr * cr / (sr.normal * wi));
}

RGBColor PerfectSpecular::sample_f(const ShadeInfo& sr, Vector3D& wi, const Vector3D& wo, float& pdf) const{
    float ndotwo = sr.normal * wo;
    wi = -wo + 2.0 * sr.normal * ndotwo;
    pdf = fabs(sr.normal * wi);
    return (kr * cr / (sr.normal * wi));
}

RGBColor PerfectSpecular::rho(const ShadeInfo& sr, const Vector3D& wo) const{
    return black;
}