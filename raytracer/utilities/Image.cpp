#include "Image.hpp"
#include "../world/ViewPlane.hpp"
#include "RGBColor.hpp"
#include <fstream>

Image::Image(int hres, int vres) : hres(hres), vres(vres)
{
    colors = new RGBColor *[hres * vres];

    for (int i = 0; i < hres; i++)
    {
        for (int j = 0; j < vres; j++)
        {
            colors[i * vres + j] = new RGBColor();
        }
    }
}

Image::Image(const ViewPlane &vp) : hres(vp.get_hres()), vres(vp.get_vres())
{
    colors = new RGBColor *[hres * vres];

    for (int i = 0; i < hres; i++)
    {
        for (int j = 0; j < vres; j++)
        {
            colors[i * vres + j] = new RGBColor();
        }
    }
}

Image::~Image()
{
    for (int i = 0; i < hres; i++)
    {
        for (int j = 0; j < vres; j++)
        {
            delete colors[i * vres + j];
        }
    }

    delete colors;
}

void Image::set_pixel(int x, int y, const RGBColor &color)
{
    *colors[y * vres + x] = color;
}

void Image::write_ppm(std::string path) const
{
    std::ofstream out(path);
    out << "P3\n"
        << hres << " " << vres << "\n255\n";
    for (int i = 0; i < hres * vres; i++)
    {
        out << (int)(colors[i]->r * 255) << " " << (int)(colors[i]->g * 255) << " " << (int)(colors[i]->b * 255) << "\n";
    }
    out.close();
}