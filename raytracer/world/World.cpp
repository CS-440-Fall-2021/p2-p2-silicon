#include "World.hpp"
#include <iostream>
#include "../cameras/Camera.hpp"
#include "../geometry/Geometry.hpp"
#include "../utilities/ShadeInfo.hpp"
#include "../utilities/Constants.hpp"

World::World() : camera_ptr(nullptr), sampler_ptr(nullptr), tracer_ptr(nullptr)
{
}


World::~World()
{
    delete camera_ptr;
    delete sampler_ptr;
}

void World::add_geometry(Geometry *geom_ptr)
{
    this->geometry.push_back(geom_ptr);
}

void World::set_camera(Camera *c_ptr)
{
    this->camera_ptr = c_ptr;
}

ShadeInfo World::hit_objects(const Ray &ray)
{
    std::vector<Geometry *>::iterator itr;

    ShadeInfo final(*this);
    ShadeInfo tmp(*this);

    final.hit = false;
    final.t = kHugeValue;
    float t = 0.0;


    for (int i = 0; i < geometry.size(); i++)
    {
        bool hit_flag = geometry[i]->hit(ray, t, tmp);

        if (hit_flag && final.t > t)
        {
            final = tmp;
        }
    }

    return final;
}
