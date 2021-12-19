#include "ViewPlane.hpp"

ViewPlane::ViewPlane() : normal(0, 0, 1), hres(640), vres(480)
{

    top_left.x = -320;
    top_left.y = 240;

    bottom_right.x = -320 + hres;
    bottom_right.y = 240 - vres;

}

int ViewPlane::get_hres() const
{
    return hres;
}

void ViewPlane::set_hres(int val)
{
    hres = val;
}

int ViewPlane::get_vres() const
{
    return vres;
}

void ViewPlane::set_vres(int val)
{
    vres = val;
}