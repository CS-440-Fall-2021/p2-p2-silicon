#include "BRDF.hpp"

BRDF::BRDF(): sampler_ptr(nullptr)
{    
}

BRDF::BRDF(Sampler* s): sampler_ptr(s)
{    
}

void BRDF::set_sampler(Sampler *s)
{
    sampler_ptr = s;
}