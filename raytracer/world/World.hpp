#pragma once

/**
   This file declares the World class which contains all the information about
   the scene - geometry and materials, lights, viewplane, camera, samplers, and
   acceleration structures.

   It also traces rays through the scene.

   Courtesy Kevin Suffern.
*/

#include <vector>

#include "../utilities/RGBColor.hpp"
#include "../acceleration/acceleration.hpp"

#include "ViewPlane.hpp"

class Camera;
class Geometry;
class Ray;
class Sampler;
class ShadeInfo;
class Tracer;
class Light;
class Ambient;

class World {
public:
  ViewPlane vplane;
  RGBColor bg_color;
  std::vector<Geometry *> geometry;
  Camera *camera_ptr;
  Sampler *sampler_ptr;
  Tracer *tracer_ptr;
  Ambient *ambient_ptr;
  std::vector<Light*> lights;
  Acceleration* AP;

public:
  // Constructors.
  World(); // initialize members.

  // Destructor.
  ~World(); // free memory.

  // Add to the scene.
  void add_geometry(Geometry *geom_ptr);
  void set_camera(Camera *c_ptr);
  void add_light(Light *light_ptr);
  void set_ambient_light(Ambient* ambient_ptr);
  void set_acceleration_structure();
  void add_obj(const char *path, Material *mPtr);
  void add_ply(std::string fname, Material *mPtr, Point3D bottom,
                    Point3D top, bool makeSmooth);

  // Build scene - add all geometry, materials, lights, viewplane, camera,
  // samplers, and acceleration structures
  void build();

  // Returns appropriate shading information corresponding to intersection of
  // the ray with the scene geometry.
  ShadeInfo hit_objects(const Ray &ray);
};
