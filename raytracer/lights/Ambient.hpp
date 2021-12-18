#pragma once
#include "Light.hpp"

class Ambient: public Light{

    public:
        Ambient();
        Ambient(float ls, float col); // set luminance & color
        ~Ambient() = default;
        virtual Vector3D get_direction(const ShadeInfo& src) const;
        virtual RGBColor L(const ShadeInfo& src) const;
};
