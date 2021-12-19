#include "ShadeInfo.hpp"

ShadeInfo::ShadeInfo(World &wr) : hit(false),
    material_ptr(nullptr),
    hit_point(), normal(),
    ray(), depth(0), dir(),
    w(&wr)
{
}

ShadeInfo::ShadeInfo(const ShadeInfo& sr)
    : hit(sr.hit),
    material_ptr(sr.material_ptr), // just copy pointer
    hit_point(sr.hit_point),
    normal(sr.normal),
    ray(sr.ray), depth(sr.depth), dir(sr.dir),
    w(sr.w)
{}