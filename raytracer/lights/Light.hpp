#pragma once
#include"../utilities/RGBColor.hpp"

class Vector3D;
class ShadeInfo;


class Light{
    protected:
        bool shadows;
        float ls;
        RGBColor color;

    public:
        Light();
        ~Light() = default;
        virtual Vector3D get_direction(const ShadeInfo& src) const = 0;
        virtual RGBColor L(const ShadeInfo& src) const = 0;

};