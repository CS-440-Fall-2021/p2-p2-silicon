#include "RGBColor.hpp"
#include <math.h>
#include <algorithm>

RGBColor::RGBColor() : r(0), g(0), b(0)
{
}

RGBColor::RGBColor(float c) : r(c), g(c), b(c)
{
}

RGBColor::RGBColor(float _r, float _g, float _b) : r(_r), g(_g), b(_b)
{
}

std::string RGBColor::to_string() const
{
    std::string my_rgb = "RGBColor :: Red: " + std::to_string(r) + ", Green: " + std::to_string(g)
        + ", Blue: " + std::to_string(b);
    return my_rgb;
}

RGBColor RGBColor::operator+(const RGBColor &c) const
{
    RGBColor rgb(*this);

    rgb.r += c.r;
    rgb.g += c.g;
    rgb.b += c.b;

    limit_check(&rgb);

    return rgb;
}

RGBColor &RGBColor::operator+=(const RGBColor &c)
{
    this->r += c.r;
    this->g += c.g;
    this->b += c.b;

    limit_check(this);

    return *this;
}

RGBColor RGBColor::operator*(const float a) const
{
    RGBColor rgb(*this);

    rgb.r *= a;
    rgb.g *= a;
    rgb.b *= a;

    limit_check(&rgb);

    return rgb;
}

RGBColor &RGBColor::operator*=(const float a)
{
    this->r *= a;
    this->g *= a;
    this->b *= a;

    limit_check(this);

    return *this;
}

RGBColor RGBColor::operator/(const float a) const
{
    RGBColor rgb(*this);

    rgb.r /= a;
    rgb.b /= a;
    rgb.g /= a;

    limit_check(&rgb);

    return rgb;
}

RGBColor &RGBColor::operator/=(const float a)
{
    this->r /= a;
    this->g /= a;
    this->b /= a;

    limit_check(this);

    return *this;
}

RGBColor RGBColor::operator*(const RGBColor &c) const
{
    RGBColor rgb(*this);

    rgb.r *= c.r;
    rgb.g *= c.g;
    rgb.b *= c.b;

    limit_check(&rgb);

    return rgb;
}

bool RGBColor::operator==(const RGBColor &c) const
{
    if (this->r == c.r && this->g ==c.g && this->b ==c.b)
    {
        return true;
    }
    
    return false;
}

RGBColor RGBColor::powc(float p) const
{
    RGBColor rgb(*this);

    rgb.r = pow(rgb.r, p);
    rgb.g = pow(rgb.g, p);
    rgb.b = pow(rgb.b, p);

    limit_check(&rgb);

    return rgb;
}

float RGBColor::average() const
{
    return (this->r + this->g + this->b)/3;
}

RGBColor operator*(const float a, const RGBColor &c)
{
    return c * a;

}

void limit_check(RGBColor *c)
{
    c->r = std::max(c->r, (float) 0.0);
    c->r = std::min(c->r, (float) 1.0);

    c->g = std::max(c->g, (float) 0.0);
    c->g = std::min(c->g, (float) 1.0);
    
    c->b = std::max(c->b, (float) 0.0);
    c->b = std::min(c->b, (float) 1.0);
    
}