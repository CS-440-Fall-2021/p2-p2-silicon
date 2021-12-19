#include "Camera.hpp"


Camera::Camera() : eye(), lookat(), up(0, 1, 0), exposure_time()
{
}

Camera::Camera(Point3D eye_, Point3D lookat_, Vector3D up_) 
    : eye(eye_), lookat(lookat_), up(up_), exposure_time(1.0)
{
}

Camera::Camera(Point3D eye_, Point3D lookat_, Vector3D up_, float exp_t) 
    : eye(eye_), lookat(lookat_), up(up_), exposure_time(exp_t)
{
}


void
Camera::compute_uvw(void)
{
    // w = lookat - eye;
    w = eye - lookat;
    w.normalize();
    u = up ^ w;
    u.normalize();
    v = w ^ u;

}

void Camera::set_eye(float x_, float y_, float z_)
{
    eye = Point3D(x_, y_, z_);
}
void Camera::set_lookat(float x_, float y_, float z_)
{
    lookat = Point3D(x_, y_, z_);
}