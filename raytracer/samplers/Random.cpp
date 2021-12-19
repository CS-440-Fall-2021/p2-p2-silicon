#include "Random.hpp"
#include "../utilities/Ray.hpp"
#include "../world/ViewPlane.hpp"
#include "../cameras/Camera.hpp"

Random::Random(Camera *c_ptr, ViewPlane *v_ptr, int num_samp) : Sampler(c_ptr, v_ptr, num_samp)
{
}

Random::Random(const Random &sampler) 
    : Sampler(sampler.camera_ptr, sampler.viewplane_ptr, 1)
{
}

Random &Random::operator=(const Random &other)
{
    this->camera_ptr = other.camera_ptr;
    this->viewplane_ptr = other.viewplane_ptr;
    this->num_samples = other.num_samples;
    this->num_sets = other.num_sets;

    return *this;
}

void Random::generate_samples()
{
    for (size_t x = 0; x < viewplane_ptr->hres; x++)
    {
        for (size_t y = 0; y < viewplane_ptr->vres; y++)
        {
            for(size_t s = 0; s < num_samples; s++){
                float x_coord = viewplane_ptr->top_left.x + ((float)x / (float)viewplane_ptr->hres) *
                                (viewplane_ptr->bottom_right.x - viewplane_ptr->top_left.x) + ((float)rand() / (float)RAND_MAX);

                // do the same for vres range
                float y_coord = viewplane_ptr->top_left.y - ((float)y / (float)viewplane_ptr->vres) *
                                (viewplane_ptr->top_left.y - viewplane_ptr->bottom_right.y) + ((float)rand() / (float)RAND_MAX);

                Point3D origin(x_coord, y_coord, viewplane_ptr->top_left.z);
                samples.push_back(origin);

            }
        }
    }
}

std::vector<Ray> Random::get_rays(int px, int py) const
{
    std::vector<Ray> rays;

    // add into top left the px values scaled from hres range 
    // into the viewplane range
    
    Point3D origin = samples[ py * viewplane_ptr->hres + px];
    
    Ray ray(origin, camera_ptr->ray_direction(origin));
    rays.push_back(ray);

    return rays;
}