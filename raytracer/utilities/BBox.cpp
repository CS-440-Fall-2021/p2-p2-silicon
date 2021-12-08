#include "BBox.hpp"
#include "../geometry/Geometry.hpp"
#include <iostream>
#include <sstream>

BBox::BBox(const Point3D& min, const Point3D& max) : pmin(min), pmax(max)
{
}

std::string BBox::to_string() const{
    std::stringstream ss;
    ss << "pmin: " << pmin.to_string() << "\n";
    ss << "pmax: " << pmax.to_string();
    return ss.str();
}

bool BBox::hit(const Ray &ray, float &t_enter, float &t_exit) const{
    
}

void BBox::extend(Geometry* g){
    pmin = min(g->getBBox().pmin, pmin);
    pmax = max(g->getBBox().pmax, pmax);
}

void BBox::extend(const BBox& b){
    pmin = min(b.pmin, pmin);
    pmax = min(b.pmax, pmax);
}

bool BBox::contains(const Point3D& p){
    if( (p.x > pmin.x && p.x < pmax.x) && (p.y > pmin.y && p.y < pmax.y) && p.z > pmin.z && p.z < pmax.z){
        return true;
    }
    return false;
}

bool BBox::overlaps(Geometry* g){
    
}

bool BBox::overlaps(const BBox& b){

}