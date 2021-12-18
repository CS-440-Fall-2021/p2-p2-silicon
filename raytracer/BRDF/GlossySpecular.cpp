#include "GlossySpecular.hpp"
#include "../utilities/Constants.hpp"
#include <math.h>


GlossySpecular::GlossySpecular() : BRDF()
{
}

GlossySpecular::GlossySpecular(Sampler *s) : BRDF(s)
{
}


void GlossySpecular::set_ks(float ks){
    this->ks = ks;
}
float GlossySpecular::get_ks(){
    return ks;
}

void GlossySpecular::set_cs(RGBColor cs){
    this->cs = cs;
}
RGBColor GlossySpecular::get_cs(){
    return cs;
}

void GlossySpecular::set_exp(float _exp)
{
    exp = _exp;
}

RGBColor GlossySpecular::f(const ShadeInfo& sr, const Vector3D& wi, const Vector3D& wo) const{
    RGBColor L;
    float ndotwi = sr.normal * wi;
    Vector3D r(-wi + 2.0 * sr.normal * ndotwi);
    float rdotwo = r * wo;
    if ((r * wo) > 0.0){
        L = ks * pow(rdotwo, exp);
    }
    return (L);
}
RGBColor GlossySpecular::sample_f(const ShadeInfo& sr, Vector3D& wi, const Vector3D& wo) const{

}

RGBColor GlossySpecular::sample_f(const ShadeInfo& sr, Vector3D& wi, const Vector3D& wo,float& pdf) const{
    // float ndotwo = sr.normal * wo;
    // Vector3D r = -wo + 2.0 * sr.normal * ndotwo; // direction of mirror
    // // reflection
    // Vector3D w = r;
    // Vector3D u = Vector3D(0.00424, 1, 0.00764) ^ w;
    // u.normalize();
    // Vector3D v = u ^ w;
    // Point3D sp = sampler_ptr->sample_hemisphere();
    // wi = sp.x * u + sp.y * v + sp.z * w; // reflected ray direction
    // if (sr.normal * wi < 0.0) // reflected ray is below surface
    // wi = -sp.x * u - sp.y * v + sp.z * w;
    // float phong_lobe = pow(r * wi, exp);
    // pdf = phong_lobe * (sr.normal * wi);
    // return (ks * cs * phong_lobe);
}

RGBColor GlossySpecular::rho(const ShadeInfo& sr, const Vector3D& wo) const{
    return black;
}