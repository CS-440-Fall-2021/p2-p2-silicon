#include "World.hpp"
#include <iostream>
#include "../cameras/Camera.hpp"
#include "../geometry/Geometry.hpp"
#include "../utilities/ShadeInfo.hpp"
#include "../utilities/Constants.hpp"
#include "../lights/Ambient.hpp"
#include "../acceleration/grid.hpp"

World::World() : camera_ptr(nullptr), sampler_ptr(nullptr), tracer_ptr(nullptr), ambient_ptr(nullptr)
{
}


World::~World()
{
    // delete camera_ptr;
    // delete sampler_ptr;
}

void World::add_light(Light* light_ptr)
{
    this->lights.push_back(light_ptr);
}

void World::add_geometry(Geometry *geom_ptr)
{
    this->geometry.push_back(geom_ptr);
}

void World::set_camera(Camera *c_ptr)
{
    this->camera_ptr = c_ptr;
}

void World::set_ambient_light(Ambient *a)
{
    ambient_ptr = a;
}

ShadeInfo World::hit_objects(const Ray &ray)
{
    std::vector<Geometry *>::iterator itr;

    ShadeInfo final(*this);
    ShadeInfo tmp(*this);

    final.hit = false;
    final.t = kHugeValue;
    float t = 0.0;


    if(AP == false){
        for(auto& G: geometry){
            G->hit(ray, final.t, final);
        }
    }
    else{
        AP->hit(ray, final.t, final);
    }

    // Seems redundant
    // for (int i = 0; i < (int) geometry.size(); i++)
    // {
    //     bool hit_flag = geometry[i]->hit(ray, t, tmp);
    //     if (hit_flag && final.t > t)
    //     {
    //         final = tmp;
    //     }
    // }

    return final;
}

void World::set_acceleration_structure() {
    AP = new Grid(geometry);
}