#include"Material.hpp"
#include"../BRDF/Lambertian.hpp"
#include"../BRDF/GlossySpecular.hpp"


class Phong : public Material
{
    protected:
        Lambertian *ambient_brdf;
        Lambertian *diffuse_brdf;
        GlossySpecular *specular_brdf;
    public:
        Phong();
        virtual RGBColor shade(const ShadeInfo &s) const override; 
};