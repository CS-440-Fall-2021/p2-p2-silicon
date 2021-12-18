#include <iostream>

#include "materials/Cosine.hpp"


#include "utilities/Image.hpp"
#include "utilities/RGBColor.hpp"
#include "utilities/Ray.hpp"
#include "utilities/ShadeInfo.hpp"

#include "world/World.hpp"
#include "world/ViewPlane.hpp"
#include "cameras/Camera.hpp"

#include "tracers/Tracer.hpp" // raytracer to be used

int main(int argc, char **argv)
{
  World world;
  world.build();
  world.camera_ptr->render_scene(world);
 

  std::cout << "Wrote image.\n";

  return 0;
}
