#ifndef GEOMETRY_H
#define GEOMETRY_H

#include "math.h"

typedef struct cube
{
    const int vertex_counts = 8;
    const int triangle_counts = 12;

    const Vector3f vertex_pos[8] = {
        {1.0f, 1.0f, -1.0f},
        {1.0f, -1.0f, -1.0f},
        {-1.0f, -1.0f, -1.0f},
        {-1.0f, 1.0f, -1.0f},
        {1.0f, 1.0f, 1.0f},
        {-1.0f, 1.0f, 1.0f},
        {-1.0f, -1.0f, -1.0f},
        {1.0f, -1.0f, -1.0f},
    };

    // Which three points form a triangle
    const Vector3i triangles[12] = {
        {0, 1, 2},
        {2, 3, 0},
        {4, 5, 6},
        {6, 7, 4},
        {0, 4, 7},
        {7, 1, 0},
        {1, 7, 6},
        {6, 2, 1},
        {2, 6, 5},
        {5, 3, 2},
        {4, 0, 3},
        {3, 5, 4}};

    Vector2f projected_vertex[8]; // (x, y) screen space
};

#endif
