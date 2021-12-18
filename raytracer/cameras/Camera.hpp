#pragma once

/**
   This file declares the Camera class which is an abstract class for concrete
   cameras to inherit from. A camera views the world through a view plane.

   Courtesy Kevin Suffern.
*/

#include "../utilities/Point3D.hpp"
#include "../utilities/Vector3D.hpp"

class World;

class Camera {
  protected:
  Point3D eye;
  Point3D lookat;
  Vector3D up;
  Vector3D u, v, w;
  float exposure_time;

public:
  // Constructors.
  Camera();
  Camera(Point3D eye_, Point3D lookat_, Vector3D up_);
  Camera(Point3D eye_, Point3D lookat_, Vector3D up_, float exp_t);

  // Copy constuctor and assignment operator.
  Camera(const Camera &camera) = default;
  Camera &operator=(const Camera &other) = default;

  // Desctructor.
  virtual ~Camera() = default;

  // Get direction of projection for a point.
  virtual Vector3D ray_direction(const Point3D &p) const = 0;

  void set_eye(float x_, float y_, float z_);
  void set_lookat(float x_, float y_, float z_);

  virtual void set_view_distance(float) = 0;
  void
  compute_uvw(void);

  // Render scene for each Camera type
  virtual void
  render_scene(World &w) = 0;
};
