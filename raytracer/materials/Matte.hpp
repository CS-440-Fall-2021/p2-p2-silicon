#include "../materials/Material.hpp"
#include "../BRDF/Lambertian.hpp"

class Matte : public Material
{
public:
    Matte();
    Matte(float ka, float kd, const RGBColor c);

    virtual ~Matte() = default;
    void set_ka(const float k);
    void set_kd(const float k);
    void set_cd(const RGBColor c);
    virtual RGBColor shade(const ShadeInfo &sr) const override;

private:
    Lambertian *ambient_brdf;
    Lambertian *diffuse_brdf;
};