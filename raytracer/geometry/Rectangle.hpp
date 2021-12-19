#pragma once

// 	Copyright (C) Kevin Suffern 2000-2007.
//	This C++ code is for non-commercial purposes only.
//	This C++ code is licensed under the GNU General Public License Version 2.
//	See the file COPYING.txt for the full license.

#include "../samplers/Sampler.hpp"
#include "Geometry.hpp"
#include "../utilities/Vector3D.hpp"
#include "../utilities/ShadeInfo.hpp"

class Rectangle : public Geometry
{
public:
    Rectangle(void);

    Rectangle(const Point3D &_p0, const Vector3D &_a, const Vector3D &_b);

    Rectangle(const Point3D &_p0, const Vector3D &_a, const Vector3D &_b, const Vector3D &n);

    virtual Rectangle *
    clone(void) const;

    Rectangle(const Rectangle &r);

    virtual ~Rectangle(void);

    Rectangle &
    operator=(const Rectangle &rhs);

    BBox
    getBBox() const override;

    virtual bool
    hit(const Ray &ray, float &t, ShadeInfo &s) const override;

    // the following functions are used when the rectangle is a light source

    virtual void
    set_sampler(Sampler *sampler);

    // virtual Point3D
    // sample(void);

    virtual Vector3D
    get_normal(const Point3D &p);

    virtual float
    pdf(ShadeInfo &sr);

    virtual std::string to_string() const override;

private:
    Point3D p0;           // corner vertex
    Vector3D a;           // side
    Vector3D b;           // side
    double a_len_squared; // square of the length of side a
    double b_len_squared; // square of the length of side b
    Vector3D normal;

    float area;           // for rectangular lights
    float inv_area;       // for rectangular lights
    Sampler *sampler_ptr; // for rectangular lights

};
