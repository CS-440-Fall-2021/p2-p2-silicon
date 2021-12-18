#pragma once
#include "Light.hpp"
#include "../utilities/Vector3D.hpp"
#include "../utilities/ShadeInfo.hpp"

class PointLight: public Light{
    protected:
        Vector3D location;
    public:
        PointLight();
        ~PointLight() = default;
        virtual Vector3D get_direction(const ShadeInfo& src) const;
        virtual RGBColor L(const ShadeInfo& src) const;
};
