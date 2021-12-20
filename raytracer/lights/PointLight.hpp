#pragma once
#include "Light.hpp"
#include "../utilities/Vector3D.hpp"
#include "../utilities/ShadeInfo.hpp"

class PointLight: public Light{
    protected:
        Vector3D location;
        
    public:
        PointLight();
        virtual ~PointLight() = default;

        void set_location(float _x, float _y, float _z);
        virtual Vector3D get_direction(const ShadeInfo& src) const;
        virtual RGBColor L(const ShadeInfo& src) const;
};
