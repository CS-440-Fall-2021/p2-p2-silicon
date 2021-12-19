#include "Compound.hpp"
#include "../utilities/BBox.hpp"
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

bool Compound::hit(const Ray& R, float& t, ShadeInfo& SI){
    bool hit = false;
    int total_objects = objects.size();
    for(int i; i < total_objects; i++){
        hit |= objects[i]->hit(R, t, SI);
    }

    return hit;
}

BBox Compound::getBBox() const{
    BBox bbox;
    int total_objects = objects.size();
    for(int i; i < total_objects; i++){
        bbox.extend(objects[i]->getBBox());
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