
/**
   This builds a scene that consists of 35 shaded spheres and a plane.
   Perspective viewing is used with a single sample per pixel.
   The spheres are the same as those in the Chapter 14 page one image. 

   Courtesy Kevin Suffern.
*/

// #include "../cameras/Parallel.hpp"
#include "../cameras/Pinhole.hpp"

#include "../geometry/Plane.hpp"
#include "../geometry/Sphere.hpp"

#include "../materials/Cosine.hpp"
#include "../materials/Matte.hpp"

#include "../tracers/Basic.hpp"

#include "../samplers/Simple.hpp"
#include "../samplers/Random.hpp"
#include "../samplers/Regular.hpp"

#include "../utilities/Constants.hpp"
#include "../utilities/Vector3D.hpp"

#include "../lights/Light.hpp"
#include "../lights/Ambient.hpp"
#include "../lights/PointLight.hpp"

#include "../world/World.hpp"

void
World::build(void) {
  // view plane  
  vplane.top_left.x = -8;
  vplane.top_left.y = 8;
  vplane.top_left.z = 30;
  vplane.bottom_right.x = 8;
  vplane.bottom_right.y = -8;
  vplane.bottom_right.z = 30;
  vplane.hres = 800;
  vplane.vres = 800;

  tracer_ptr = new Basic(this);
  
  bg_color = black;  // background color.
  
  // camera and sampler.
  Camera *cam = new Pinhole();
  cam->set_eye(0, 0, 20);
  cam->set_lookat(0, 0, 0);
  cam->set_view_distance(500);
  // Camera *cam = new Pinhole(Point3D(-320, 240, -310), Point3D(-320, 240, 0), 300);
  cam->compute_uvw();
  set_camera(cam);
  
  sampler_ptr = new Simple(camera_ptr, &vplane);
  // sampler_ptr = new Random(camera_ptr, &vplane, 16);
  // sampler_ptr = new Regular(camera_ptr, &vplane, 16);
  sampler_ptr->generate_samples();
	
  // default luminance 1.0, color 1.0
  Ambient *ambient = new Ambient();
  set_ambient_light(ambient);
  ambient->scale_radiance(20.0);


  PointLight *pt_light = new PointLight();
  pt_light->set_location(-20, 10, 10);
  pt_light->scale_radiance(5.0);
  add_light(pt_light);

  // colors
  RGBColor yellow(1, 1, 0);  // yellow
  RGBColor brown(0.71, 0.40, 0.16);  // brown
  RGBColor darkGreen(0.0, 0.41, 0.41);  // darkGreen
  RGBColor orange(1, 0.75, 0);  // orange
  RGBColor green(0, 0.6, 0.3);  // green
  RGBColor lightGreen(0.65, 1, 0.30);  // light green
  RGBColor darkYellow(0.61, 0.61, 0);  // dark yellow
  RGBColor lightPurple(0.65, 0.3, 1);  // light purple
  RGBColor darkPurple(0.5, 0, 1);  // dark purple
  RGBColor grey(0.25);  // grey
	

  
  add_obj("./testmonke.obj", new Cosine(orange));
}

