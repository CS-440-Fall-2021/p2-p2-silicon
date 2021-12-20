#include "../happly/happly.h"
#include "../world/World.hpp"
#include "../geometry/Triangle.hpp"
#include "../utilities/Point3D.hpp"
#include "../utilities/Vector3D.hpp"

void World::add_ply(std::string fname, Material *mPtr, Point3D bottom,
                    Point3D top, bool makeSmooth)
{
    // Construct the data object by reading from file
    happly::PLYData plyIn(fname);

    // Get mesh-style data from the object
    std::vector<std::array<double, 3>> vPos = plyIn.getVertexPositions();
    std::vector<std::vector<size_t>> fInd = plyIn.getFaceIndices<size_t>();
    std::vector<Point3D> points;
    std::vector<Vector3D> normals;
    Vector3D normal;

    // for(int i = 0; i < vPos.size(); i++)
    // {
    //     vPos[i][1] = (vPos[i][1] * cos(90)) + (vPos[i][1] * -sin(90));
    //     vPos[i][2] = (vPos[i][2] * sin(90)) + (vPos[i][2] * cos(90));
    // }

    Point3D modelMin = Point3D(vPos[0][0], vPos[0][1], vPos[0][2]);
    Point3D modelMax = Point3D(vPos[0][0], vPos[0][1], vPos[0][2]);

    for (const std::array<double, 3> &point : vPos)
    {
        points.push_back(Point3D(point[0], point[1], point[2]));
        modelMin = min(modelMin, Point3D(point[0], point[1], point[2]));
        modelMax = max(modelMax, Point3D(point[0], point[1], point[2]));
    }

    for (Point3D &point : points)
    {
        point = interpolate(modelMin, modelMax, point, bottom, top);
    }

    // prepare normals array
    if (makeSmooth)
    {
        normals.resize(vPos.size());
    }

    // loop through faces
    for (std::vector<size_t> face : fInd)
    {
        if (makeSmooth)
        {
            // calculate normals
            normal = ((points[face[1]] - points[face[0]]) ^
                      (points[face[2]] - points[face[0]]));
            normal.normalize();
            for (size_t vIndex : face)
            {
                normals[vIndex] += normal;
            }
        }
        else
        {
            Triangle *fTriangle =
                new Triangle(points[face[0]], points[face[1]], points[face[2]]);
            fTriangle->set_material(mPtr);
            add_geometry(fTriangle);
        }
    }

    // if (makeSmooth)
    // {
    //     for (size_t n = 0; n < normals.size(); ++n)
    //     {
    //         normals[n].normalize();
    //     }
    //     // add smooth triangles
    //     for (std::vector<size_t> face : fInd)
    //     {
    //         SmoothTriangle *fSTriangle = new SmoothTriangle(
    //             points[face[0]], points[face[1]], points[face[2]], normals[face[0]],
    //             normals[face[1]], normals[face[2]]);
    //         fSTriangle->set_material(mPtr->clone());
    //         add_geometry(fSTriangle);
    //     }
    // }

}