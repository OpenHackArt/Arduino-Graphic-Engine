#ifndef GEOMETRY_H
#define GEOMETRY_H

#include "data_structure.h"

typedef struct cube
{
    int vertex_counts = 8;
    int tri_counts = 12;

    Vector3f vertex_pos[8] = {
        {15.0f, 15.0f, -15.0f},
        {15.0f, -15.0f, -15.0f},
        {-15.0f, -15.0f, -15.0f},
        {-15.0f, 15.0f, -15.0f},
        {15.0f, 15.0f, 15.0f},
        {-15.0f, 15.0f, 15.0f},
        {-15.0f, -15.0f, -15.0f},
        {15.0f, -15.0f, -15.0f},
    };
};

#endif
