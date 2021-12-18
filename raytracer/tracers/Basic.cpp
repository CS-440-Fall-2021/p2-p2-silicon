#include "Basic.hpp"
#include "../world/World.hpp"
#include "../utilities/Ray.hpp"
#include "../utilities/ShadeInfo.hpp"
#include "../materials/Material.hpp"

Basic::Basic(World *_w) : Tracer(_w)
{
}

RGBColor Basic::trace_ray(const Ray &ray, const int depth) const
{
    RGBColor m_color(0);
    float weight = ray.w; // ray weight for the pixel.
    ShadeInfo sinfo = w->hit_objects(ray);
    if (sinfo.hit)
    {
        m_color += weight * sinfo.material_ptr->shade(sinfo);
    }
    else
    {
        m_color += weight * w->bg_color;
    }

    return m_color;
}


