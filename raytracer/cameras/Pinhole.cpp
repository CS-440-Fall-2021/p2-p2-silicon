#include "Pinhole.hpp"
#include "../utilities/Point3D.hpp"
#include "../utilities/Vector3D.hpp"

#include "../samplers/Sampler.hpp"

#include "../utilities/Image.hpp"
#include "../utilities/RGBColor.hpp"
#include "../utilities/Ray.hpp"
#include "../utilities/ShadeInfo.hpp"

#include "../world/World.hpp"
#include "../world/ViewPlane.hpp"

#include "../tracers/Tracer.hpp" // raytracer to be used


Pinhole::Pinhole(): Camera(), d(0), zoom(1)
{
}

Pinhole::Pinhole(Point3D eye, Point3D lookat, float d_) 
    : Camera(eye, lookat, Vector3D(0, 1, 0)), d(d_)
{
}

Pinhole::Pinhole(Point3D eye, Point3D lookat, Vector3D up, 
    float exposure_time, float d_, float zoom_)
    : Camera(eye, lookat, up), d(d_), zoom(zoom_)
{
}

void Pinhole::set_view_distance(float d_)
{
    d = d_;
}

Vector3D Pinhole::ray_direction(const Point3D &p) const
{
    Vector3D dir = p.x * u + p.y * v - d *w;
    dir.normalize();
    return dir;
}

void Pinhole::render_scene(World &w)
{
    Sampler *sampler = w.sampler_ptr;
    ViewPlane &viewplane = w.vplane;
    Image image(viewplane);

    std::vector<Ray> rays;
    for (int x = 0; x < viewplane.hres; x++) // across.
    { 
        for (int y = 0; y < viewplane.vres; y++) // down.
        { 
            // Get rays for the pixel from the sampler. The pixel color is the
            // weighted sum of the shades for each ray.
            RGBColor pixel_color(0);
            rays = sampler->get_rays(x, y);
            for (const auto &ray : rays)
            {
                pixel_color += w.tracer_ptr->trace_ray(ray, 0);
            }
            
            // TODO:
            // Divide color by num of samples (rays.size) * exposure time
            pixel_color /= rays.size();
            // Save color to image.
            image.set_pixel(x, y, pixel_color);
            // std::cout << pixel_color << "\n";
        }
    }
    // Write image to file.
    image.write_ppm("scene.ppm");
}
