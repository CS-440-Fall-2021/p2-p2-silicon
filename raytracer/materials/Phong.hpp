#pragma once

#include "../materials/Material.hpp"
#include "../BRDF/Lambertian.hpp"
#include "../BRDF/GlossySpecular.hpp"


class Phong : public Material
{
    protected:
        Lambertian *ambient_brdf;
        Lambertian *diffuse_brdf;
        GlossySpecular *specular_brdf;
    public:
        Phong();
        ~Phong() =default;


        void set_ambient(Lambertian *ambient);
        void set_diffuse(Lambertian *diffuse);
        void set_specular(GlossySpecular *specular);
        virtual void set_sampler(Sampler *s);

        void set_ka(float ka);
        void set_kd(float kd);
        void set_cd(RGBColor cd);
        void set_ks(float ks);
        void set_exp(float exp);


        virtual RGBColor shade(const ShadeInfo &s) const override; 
};