// Credit: Matthew Calligaro <matthewcalligaro@hotmail.com>

#include "../cameras/Pinhole.hpp"

#include "../geometry/Plane.hpp"
#include "../geometry/Sphere.hpp"
#include "../geometry/Triangle.hpp"

#include "../materials/Cosine.hpp"
#include "../materials/Matte.hpp"
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
  vplane.top_left.x = -200/2;
  vplane.top_left.y = 200/2;
  vplane.top_left.z = 50;
  vplane.bottom_right.x = 200/2;
  vplane.bottom_right.y = -200/2;
  vplane.bottom_right.z = 50;
  vplane.hres = 400*2;
  vplane.vres = 400*2;
  vplane.max_depth = 10;

  tracer_ptr = new Whitted(this);

  // camera and sampler.
  // Camera *cam = new Pinhole();
  // cam->set_eye(0, 0, -50);
  // cam->set_lookat(0, 0, 0);
  // cam->set_view_distance(10);
  Camera *cam = new Pinhole(Point3D(-320, 240, 100), Point3D(-320, 240, 0), 1000);
  cam->compute_uvw();
  set_camera(cam);
  sampler_ptr = new Simple(camera_ptr, &vplane);
  // sampler_ptr = new Random(camera_ptr, &vplane,16);
  sampler_ptr->generate_samples();
	
  // default luminance 1.0, color 1.0
  Ambient *ambient = new Ambient();
  set_ambient_light(ambient);

  PointLight *pt_light = new PointLight();
  pt_light->set_location(-30, 50, 0);
  pt_light->scale_radiance(3.0);
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
	
  // Background color.
  bg_color = grey;

  for (int x = -3200; x <= 3200; x += 2) {
    for (int y = -3200; y <= 3200; y += 2) {
      Sphere* s = new Sphere(Point3D(x, y, 0), 1);
      s->set_material(new Matte((x + 3200.0) / 6400.0, 0, (y + 3200.0) / 6400.0));
      add_geometry(s);
    }
  }
}
