#include"BRDF.hpp"

class PerfectSpecular: public BRDF{
    private:
        float kr;
        RGBColor cr;
    public:
        PerfectSpecular();
        ~PerfectSpecular() = default;

        // Access functions for kd and cd
        void set_kr(float kr);
        void set_cr(RGBColor cr);
        float get_kr();
        RGBColor get_cr();

        virtual RGBColor f(const ShadeInfo& sr, const Vector3D& wi, const Vector3D& wo) const;
        virtual RGBColor sample_f(const ShadeInfo& sr, Vector3D& wi, const Vector3D& wo) const;
        virtual RGBColor sample_f(const ShadeInfo& sr, Vector3D& wi, const Vector3D& wo,float& pdf) const;
        virtual RGBColor rho(const ShadeInfo& sr, const Vector3D& wo) const;
};