#include "Sampler.hpp"
#include <math.h>
#include "../utilities/Point3D.hpp"
#include "../world/ViewPlane.hpp"
#include "../utilities/Constants.hpp"

Sampler::Sampler(int num_samp)
    : camera_ptr(nullptr), viewplane_ptr(nullptr), num_samples(num_samp)
{
}

Sampler::Sampler(Camera *c_ptr, ViewPlane *v_ptr, int num_samp)
    : camera_ptr(c_ptr), viewplane_ptr(v_ptr), num_samples(num_samp),
      num_sets(v_ptr->hres * v_ptr->vres)
{
}

void Sampler::map_samples_to_hemisphere(const float e)
{
    int size = samples.size();
    this->hemishpere_samples.reserve(num_samples * num_sets);
    for (int j = 0; j < size; j++)
    {
        float cos_phi = cos(2.0 * PI * samples[j].x);
        float sin_phi = sin(2.0 * PI * samples[j].x);
        float cos_theta = pow((1.0 - samples[j].y), 1.0 / (e + 1.0));
        float sin_theta = sqrt(1.0 - cos_theta * cos_theta);
        float pu = sin_theta * cos_phi;
        float pv = sin_theta * sin_phi;
        float pw = cos_theta;
        this->hemishpere_samples.push_back(Point3D(pu, pv, pw));
    }
}