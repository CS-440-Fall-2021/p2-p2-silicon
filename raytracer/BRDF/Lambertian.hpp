#pragma once
#include "BRDF.hpp"

class Lambertian: public BRDF{
    private:
        float kd;
        RGBColor cd;
    public:
        Lambertian();
        Lambertian(Sampler*);
        ~Lambertian() = default;

        // Access functions for kd and cd
        void set_kd(float kd);
        void set_cd(RGBColor cd);
        float get_kd();
        RGBColor get_cd();

        virtual RGBColor f(const ShadeInfo& sr, const Vector3D& wi, const Vector3D& wo) const;
        virtual RGBColor sample_f(const ShadeInfo& sr, Vector3D& wi, const Vector3D& wo) const;
        virtual RGBColor sample_f(const ShadeInfo& sr, Vector3D& wi, const Vector3D& wo,float& pdf) const;
        virtual RGBColor rho(const ShadeInfo& sr, const Vector3D& wo) const;
};