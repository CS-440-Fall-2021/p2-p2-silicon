#include"PerfectSpecular.hpp"
#include"../utilities/Constants.hpp"

void PerfectSpecular::set_kr(float kr){
    this->kr = kr;
}
void PerfectSpecular::set_cr(RGBColor cd){
    this->cr = cr;
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

RGBColor PerfectSpecular::sample_f(const ShadeInfo& sr, Vector3D& wi, const Vector3D& wo,float& pdf) const{
    
}

RGBColor PerfectSpecular::rho(const ShadeInfo& sr, const Vector3D& wo) const{
    return black;
}