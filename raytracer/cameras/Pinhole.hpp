#pragma once

/**
   This file declares the Perspective class which represents a perspective
   viewing camera.

   Courtesy Kevin Suffern.
*/

#include "Camera.hpp"


class Pinhole : public Camera {
protected:
  float d; // view-plane distance
  float zoom; // zoom factor

public:
  // Constructors.
  Pinhole();

  Pinhole(Point3D eye, Point3D lookat, float d_);

  Pinhole(Point3D eye, Point3D lookat, Vector3D up, 
    float exposure_time, float d_, float zoom_);

  // Copy constuctor and assignment operator.
  Pinhole(const Pinhole &camera);
  Pinhole &operator=(const Pinhole &other);

  // Desctructor.
  virtual ~Pinhole() = default;

  virtual void set_view_distance(float d_) override;

  virtual void render_scene(World &w) override;

  // Get direction of projection for a point.
  virtual Vector3D ray_direction(const Point3D &p) const override;
};
