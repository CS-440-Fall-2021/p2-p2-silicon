#pragma once

#include "../samplers/Sampler.hpp"
#include "../utilities/ShadeInfo.hpp"
#include "../utilities/Vector3D.hpp"
#include "../utilities/RGBColor.hpp"
#include "../utilities/Point3D.hpp"


class BRDF{
    protected:
        Sampler * sampler_ptr;
    public:
        BRDF();
        BRDF(Sampler *);

        ~BRDF() = default;

        void set_sampler(Sampler *);
        virtual RGBColor f(const ShadeInfo& sr, const Vector3D& wi, const Vector3D& wo) const = 0; 
        virtual RGBColor sample_f(const ShadeInfo& sr, Vector3D& wi, const Vector3D& wo) const = 0;
        virtual RGBColor sample_f(const ShadeInfo& sr, Vector3D& wi, const Vector3D& wo, float& pdf) const = 0;
        virtual RGBColor rho(const ShadeInfo& sr, const Vector3D& wo) const = 0;
};