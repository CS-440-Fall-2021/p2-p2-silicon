#include"BRDF.hpp"

class GlossySpecular: public BRDF{
    private:
        float ks;
        float exp;
        RGBColor cs;
    public:
        GlossySpecular();
        ~GlossySpecular() = default;

        // Access functions for kd and cd
        void set_ks(float ks);
        float get_ks();
        void set_cs(RGBColor cs);
        RGBColor get_cs();

        virtual RGBColor f(const ShadeInfo& sr, const Vector3D& wi, const Vector3D& wo) const ;
        virtual RGBColor sample_f(const ShadeInfo& sr, Vector3D& wi, const Vector3D& wo) const;
        virtual RGBColor sample_f(const ShadeInfo& sr, Vector3D& wi, const Vector3D& wo,float& pdf) const;
        virtual RGBColor rho(const ShadeInfo& sr, const Vector3D& wo) const;
};