#pragma once

#include "PointLight.hpp"
#include "../utilities/Vector3D.hpp"
#include <math.h>

class SpotLight: public PointLight{
    protected:
        Vector3D direction;
        float theta;

        
    public:
        SpotLight();
        ~SpotLight() = default;
        virtual Vector3D get_direction(const ShadeInfo& src) const;
        void set_direction(const Vector3D& d);
        void set_direction(float x, float y, float z);
        void set_theta(float t);
        virtual RGBColor L(const ShadeInfo& src) const;
};
