#include "../cameras/Pinhole.hpp"

#include "../geometry/Plane.hpp"
#include "../geometry/Sphere.hpp"
#include "../geometry/Triangle.hpp"

#include "../materials/Cosine.hpp"
#include "../materials/Matte.hpp"
#include "../materials/Phong.hpp"
#include "../materials/Reflective.hpp"

#include "../tracers/Whitted.hpp"

#include "../samplers/Simple.hpp"
#include "../samplers/Random.hpp"

#include "../utilities/Constants.hpp"
#include "../utilities/Vector3D.hpp"

#include "../lights/Light.hpp"
#include "../lights/Ambient.hpp"
#include "../lights/PointLight.hpp"

#include "../world/World.hpp"

void
World::build(void) {
  // view plane  
  vplane.top_left.x = -20;
  vplane.top_left.y = 20;
  vplane.top_left.z = 10;
  vplane.bottom_right.x = 20;
  vplane.bottom_right.y = -20;
  vplane.bottom_right.z = 10;
  vplane.hres = 400;
  vplane.vres = 400;


   tracer_ptr = new Whitted(this);
  
  bg_color = black;  // background color
  
  Camera *cam = new Pinhole(Point3D(-320, 0, 100), Point3D(-320, 0, 0), 1000);
  cam->compute_uvw();
  set_camera(cam);
	

  sampler_ptr = new Simple(camera_ptr, &vplane);
  sampler_ptr->generate_samples();

  Ambient *ambient = new Ambient();
  set_ambient_light(ambient);


  PointLight *pt_light = new PointLight();
  pt_light->set_location(-30, 50, 25);
  pt_light->scale_radiance(3.0);
  add_light(pt_light);


  //////////// COSINE //////////////////
  
   // sphere
  Sphere* sphere_ptr = new Sphere(Point3D(-3, 2, 0), 5); 
  sphere_ptr->set_material(new Cosine(red));
  add_geometry(sphere_ptr);
  
  // triangle
  Point3D a(2.5, -5, 1); 
  Point3D b(14, -1, 0); 
  Point3D c(8.5, 5, 0.5); 
  Triangle* triangle_ptr = new Triangle(a, b, c);
  triangle_ptr->set_material(new Cosine(blue));
  add_geometry(triangle_ptr);

  // plane
  Plane* plane_ptr = new Plane(Point3D(0,1,0), Vector3D(0, 10, 2)); 
  plane_ptr->set_material(new Cosine(green));  // green
  add_geometry(plane_ptr);



////////// Phong ///////////

//     Phong* Phong_ptr = new Phong;
// 	Phong_ptr->set_ka(0.7);
// 	Phong_ptr->set_kd(0.7);
// 	Phong_ptr->set_cd(red);    		
// 	Phong_ptr->set_ks(0.15);
// 	Phong_ptr->set_exp(25.0);

//     Phong* Phong_ptr2 = new Phong;
// 	Phong_ptr->set_ka(0.7);
// 	Phong_ptr->set_kd(0.7);
// 	Phong_ptr->set_cd(blue);    		
// 	Phong_ptr->set_ks(0.15);
// 	Phong_ptr->set_exp(25.0);

//     Phong* Phong_ptr3 = new Phong;
// 	Phong_ptr->set_ka(0.7);
// 	Phong_ptr->set_kd(0.7);
// 	Phong_ptr->set_cd(green);    		
// 	Phong_ptr->set_ks(0.15);
// 	Phong_ptr->set_exp(25.0);
//   // sphere
//   Sphere* sphere_ptr = new Sphere(Point3D(-3, 2, 0), 5); 
//   sphere_ptr->set_material(Phong_ptr);
//   add_geometry(sphere_ptr);
//   // triangle
//   Point3D a(2.5, -5, 1); 
//   Point3D b(14, -1, 0); 
//   Point3D c(8.5, 5, 0.5); 
//   Triangle* triangle_ptr = new Triangle(a, b, c);
//   triangle_ptr->set_material(Phong_ptr2);
//   add_geometry(triangle_ptr);

//   // plane
//   Plane* plane_ptr = new Plane(Point3D(0,1,0), Vector3D(0, 10, 2)); 
//   plane_ptr->set_material(Phong_ptr3);  // green
//   add_geometry(plane_ptr);


 //////// REFLECTIVE /////////

//   RGBColor brown(0.71, 0.40, 0.16);  // brown
    // Reflective* reflective_ptr2 = new Reflective;
    // reflective_ptr2->set_ka(0.25);
    // reflective_ptr2->set_kd(0.5);
    // reflective_ptr2->set_cd(brown);
    // reflective_ptr2->set_ks(0.25);
    // reflective_ptr2->set_exp(100);
    // reflective_ptr2->set_kr(0.75);
    // reflective_ptr2->set_cr(white);
}