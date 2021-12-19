#pragma once

#include <vector>

#include "Geometry.hpp"

using namespace std;

class Compound: public Geometry{
    private:
        vector<Geometry*> objects;
    public:
        //Constructora
        Compound();
        Compound(const Compound& C);
        Compound(vector<Geometry*> objects);

        Compound& operator = (const Compound& c);

        //Functions
        void add_object(Geometry* object);
        virtual bool hit(const Ray& R, float& t, ShadeInfo& SI);
        virtual BBox getBBox() const;
        string to_string() const override;


        //Destructor   
        virtual ~Compound();
};