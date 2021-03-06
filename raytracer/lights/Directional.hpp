#pragma once

#include "Light.hpp"
#include "../utilities/Vector3D.hpp"

class Directional: public Light{
    protected:
        Vector3D direction;
        
    public:
        Directional();
        virtual ~Directional() = default;
        virtual Vector3D get_direction(const ShadeInfo& src) const;
        void set_direction(const Vector3D& d);
        void set_direction(float x, float y, float z);
        virtual RGBColor L(const ShadeInfo& src) const;
};
