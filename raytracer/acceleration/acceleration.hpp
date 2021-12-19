#pragma once

#include <vector>

#include "../utilities/ShadeInfo.hpp"
#include "../utilities/Ray.hpp"

#include "../geometry/Geometry.hpp"

class Acceleration{
    public:
        //Constructors
        Acceleration() = default;
        Acceleration(const Acceleration &object) = default;

        //Functions
        virtual bool hit(const Ray &R, float& t, ShadeInfo &SI) const = 0;
        Acceleration &operator = (const Acceleration &object) = default;

        //Destructor
        virtual ~Acceleration() = default;
};
