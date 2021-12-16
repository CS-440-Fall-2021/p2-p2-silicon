raytracer: Parallel.o Perspective.o Geometry.o Plane.o Sphere.o Triangle.o Cosine.o Basic.o \
Sampler.o Simple.o BBox.o Image.o Point3D.o Ray.o RGBColor.o ShadeInfo.o Vector3D.o ViewPlane.o World.o Build.o raytracer.o
	g++ -o raytracer Parallel.o Perspective.o Geometry.o Plane.o Sphere.o Triangle.o Cosine.o \
Sampler.o Simple.o BBox.o Image.o Point3D.o Ray.o RGBColor.o ShadeInfo.o Vector3D.o ViewPlane.o World.o Build.o Basic.o raytracer.o

Parallel.o: cameras/Parallel.cpp
	g++ -c cameras/Parallel.cpp

Perspective.o: cameras/Perspective.cpp
	g++ -c cameras/Perspective.cpp

Geometry.o: geometry/Geometry.cpp
	g++ -c geometry/Geometry.cpp

Plane.o: geometry/Plane.cpp
	g++ -c geometry/Plane.cpp

Sphere.o: geometry/Sphere.cpp
	g++ -c geometry/Sphere.cpp

Triangle.o: geometry/Triangle.cpp
	g++ -c geometry/Triangle.cpp

Cosine.o: materials/Cosine.cpp
	g++ -c materials/Cosine.cpp

Sampler.o: samplers/Sampler.cpp
	g++ -c samplers/sampler.cpp

Simple.o: samplers/Simple.cpp
	g++ -c samplers/Simple.cpp

BBox.o: utilities/BBox.cpp
	g++ -c utilities/BBox.cpp

Image.o: utilities/Image.cpp
	g++ -c utilities/Image.cpp

Point3D.o: utilities/Point3D.cpp
	g++ -c utilities/Point3D.cpp

Ray.o: utilities/Ray.cpp
	g++ -c utilities/Ray.cpp

RGBColor.o: utilities/RGBColor.cpp
	g++ -c utilities/RGBColor.cpp

ShadeInfo.o: utilities/ShadeInfo.cpp
	g++ -c utilities/ShadeInfo.cpp

Vector3D.o: utilities/Vector3D.cpp
	g++ -c utilities/Vector3D.cpp

ViewPlane.o: world/ViewPlane.cpp
	g++ -c world/ViewPlane.cpp

World.o: world/World.cpp
	g++ -c world/World.cpp

Build.o: build/buildHelloWorld.cpp
	g++ -c build/buildHelloWorld.cpp -o Build.o

Basic.o: tracers/Basic.cpp
	g++ -c tracers/Basic.cpp

raytracer.o: raytracer.cpp
	g++ -c raytracer.cpp

clean:
	rm *.o

run: raytracer
	./raytracer

rebuild:
	clean
	raytracer
	run