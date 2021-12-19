#include "Compound.hpp"
#include "../utilities/BBox.hpp"
#include "../utilities/Vector3D.hpp"
#include "../utilities/Constants.hpp"
#include "../utilities/ShadeInfo.hpp"

//Constructor
Compound::Compound():Geometry(){

}

Compound::Compound(const Compound& C){
    objects = C.objects;
}

Compound::Compound(vector<Geometry*> objects){
    this->objects = objects;
}

//Functions
void Compound::add_object(Geometry* object) {
	objects.push_back(object);	
}

bool Compound::hit(const Ray& ray, float& tmin, ShadeInfo& sr) const {
    float	t; 
	Vector3D normal;
	Point3D	local_hit_point;
	bool hit = false;
	t = kHugeValue;
	int num_objects	= objects.size();
	
	for (int j = 0; j < num_objects; j++){
		if (objects[j]->hit(ray, t, sr) && (t <= tmin)) {
			hit				= true;
			tmin 			= t;
			material_ptr = (objects[j]->get_material());
			normal			= sr.normal;
			local_hit_point	= sr.hit_point;  
		}
	}
	
	if (hit) {
		sr.t				= tmin;
		sr.normal 			= normal;   
		sr.hit_point 	= local_hit_point;
		sr.hit = true;
		sr.material_ptr = material_ptr;
	}
	
	return (hit);
}

BBox Compound::getBBox() const{
    BBox bbox;
	for (const auto &g: objects){
		bbox.extend(g);
	}
    return bbox;
}

string Compound::to_string() const{
    string some = "";
    return some;
}

//Destructor
Compound::~Compound(){
    int total_objects = objects.size();
    for (int i = 0; i < total_objects; i++){
        delete objects[i];
    }
}