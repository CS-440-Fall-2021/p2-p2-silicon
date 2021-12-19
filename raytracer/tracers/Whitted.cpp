#include "Whitted.hpp"
#include "../utilities/RGBColor.hpp"
#include "../utilities/ShadeInfo.hpp"
#include "../materials/Material.hpp"
#include "../world/World.hpp"
#include <iostream>
Whitted::Whitted(World *world) : Tracer(world)
{
}

RGBColor Whitted::trace_ray(const Ray ray, const int depth) const
{
    if (depth > w->vplane.max_depth)
        return (RGBColor());
    else
    {
        ShadeInfo sr(w->hit_objects(ray));
        if (sr.hit)
        {
            sr.depth = depth;
            sr.ray = ray;
            return (sr.material_ptr->shade(sr));
        }
        else
            return (w->bg_color);
    }
}