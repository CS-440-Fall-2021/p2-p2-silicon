#pragma once
#include "Tracer.hpp"


class Basic : public Tracer
{
private:
    /* data */
public:
    Basic(World *);
    virtual ~Basic() = default;

    virtual RGBColor trace(Ray const &) const override;
};
