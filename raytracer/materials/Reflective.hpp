#pragma once
#include "Phong.hpp"

#include "../BRDF/PerfectSpecular.hpp"

class Reflective : public Phong
{
private:
    PerfectSpecular* reflective_brdf;
public:
    Reflective();
    ~Reflective()= default;
    
    void set_kr(float kr);
    void set_cr(RGBColor c);

    void set_reflective_brdf(PerfectSpecular *perfspec);
    virtual RGBColor shade(const ShadeInfo &s) const override;
};