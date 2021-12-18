#include "Simple.hpp"
#include "../utilities/Ray.hpp"
#include "../world/ViewPlane.hpp"
#include "../cameras/Camera.hpp"

Simple::Simple(Camera *c_ptr, ViewPlane *v_ptr) : Sampler(c_ptr, v_ptr)
{
}

Simple::Simple(const Simple &sampler) 
    : Sampler(sampler.camera_ptr, sampler.viewplane_ptr)
{
}

Simple &Simple::operator=(const Simple &other)
{
    this->camera_ptr = other.camera_ptr;
    this->viewplane_ptr = other.viewplane_ptr;

    return *this;
}

std::vector<Ray> Simple::get_rays(int px, int py) const
{
    std::vector<Ray> rays;

    // add into top left the px values scaled from hres range 
    // into the viewplane range
    
    float x_coord = viewplane_ptr->top_left.x + ((float)px/(float)viewplane_ptr->hres) * 
        (viewplane_ptr->bottom_right.x - viewplane_ptr->top_left.x);
    
    // do the same for vres range
    float y_coord = viewplane_ptr->top_left.y - ((float)py/(float)viewplane_ptr->vres) * 
        (viewplane_ptr->top_left.y - viewplane_ptr->bottom_right.y);

    Point3D origin(x_coord, y_coord, viewplane_ptr->top_left.z);
    Ray ray(origin, camera_ptr->ray_direction(origin));

    rays.push_back(ray);

    return rays;
}