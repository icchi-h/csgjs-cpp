#pragma once
#include <vector>

struct csgjs_vector {
    float x, y, z;

    csgjs_vector() : x(0.0f), y(0.0f), z(0.0f) {}
    explicit csgjs_vector(float x, float y, float z) : x(x), y(y), z(z) {}
};

struct csgjs_vertex {
    csgjs_vector pos;
    csgjs_vector normal;
    csgjs_vector uv;
};

struct csgjs_model {
    std::vector<csgjs_vertex> vertices;
    std::vector<int> indices;
};


csgjs_model csgjs_union(const csgjs_model & a, const csgjs_model & b);
csgjs_model csgjs_intersection(const csgjs_model & a, const csgjs_model & b);
csgjs_model csgjs_difference(const csgjs_model & a, const csgjs_model & b);

csgjs_model csgjs_sphere(const float radius, const int slices = 16, const int stacks = 8);
csgjs_model csgjs_cube(const int size, const int center[]);


//Header Additional Code (by shirai)

struct csgjs_plane;
struct csgjs_polygon;
struct csgjs_node;

// Represents a plane in 3D space.
struct csgjs_plane {
    csgjs_vector normal;
    float w;

    csgjs_plane();
    csgjs_plane(const csgjs_vector & a, const csgjs_vector & b, const csgjs_vector & c);
    bool ok() const;
    void flip();
    void splitPolygon(const csgjs_polygon & polygon, std::vector<csgjs_polygon> & coplanarFront, std::vector<csgjs_polygon> & coplanarBack, std::vector<csgjs_polygon> & front, std::vector<csgjs_polygon> & back) const;
};

struct csgjs_polygon {
    std::vector<csgjs_vertex> vertices;
    csgjs_plane plane;
    void flip();

    csgjs_polygon();
    csgjs_polygon(const std::vector<csgjs_vertex> & list);
};

csgjs_model csgjs_modelFromPolygons(const std::vector<csgjs_polygon> & polygons);
std::vector<csgjs_polygon> csgjs_modelToPolygons(const csgjs_model & model);

