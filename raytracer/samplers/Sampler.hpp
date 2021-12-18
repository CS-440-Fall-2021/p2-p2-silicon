#pragma once

/**
   This file declares the Sampler class which is an abstract class for concrete
   samplers to inherit from.

   A sampler samples a scene by shooting primary rays through pixels in a
   viewplane. A primary ray begins at the pixel and its direction is determined
   by a camera. Different samplers shoot different numbers of primary rays in
   different manners.

   Courtesy Kevin Suffern.
*/

#include <vector>

class Camera;
class Ray;
class ViewPlane;
class Point3D;

class Sampler {
protected:
  Camera *camera_ptr;       // the camera that decides the projectors.
  ViewPlane *viewplane_ptr; // the view plane through which rays are shot.
  int num_samples;
  int num_sets;
  mutable std::vector<Point3D> samples;
  std::vector<Point3D> hemishpere_samples;

public:
  // Constructors.
  Sampler(int num_samp);                                // initializes members to NULL.
  Sampler(Camera *c_ptr, ViewPlane *v_ptr, int num_samp); // set members.

  // Copy constuctor and assignment operator.
  Sampler(const Sampler &camera) = default;
  Sampler &operator=(const Sampler &other) = default;

  // Desctructor.
  virtual ~Sampler() = default;

  // Get rays corresponding to a pixel in the view plane. px and py are 0-based
  // indexes of the pixel in the view plane, with the origin at the top left of
  // the view plane.
  virtual std::vector<Ray> get_rays(int px, int py) const = 0;
  virtual void generate_samples() = 0;


  void sample_hemisphere();
  void map_samples_to_hemisphere(const float e);
};