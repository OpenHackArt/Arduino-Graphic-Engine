#include "geometry.h"

cube obj_cube;

sphere obj_sphere;

cone obj_cone;

face obj_face;

small_bunny obj_small_bunny;

bunny obj_bunny;

int get_vertex_cnts(unsigned char obj_index)
{
    switch (obj_index)
    {
    case INDEX_CUBE:
        return obj_cube.vertex_counts;
    case INDEX_SPHERE:
        return obj_sphere.vertex_counts;
    case INDEX_CONE:
        return obj_cone.vertex_counts;
    case INDEX_BUNNY:
        return obj_bunny.vertex_counts;
    case INDEX_SMALLBUNNY:
        return obj_small_bunny.vertex_counts;
    case INDEX_FACE:
        return obj_face.vertex_counts;
    default:
        break;
    }
    return 0;
}

int get_triangle_cnts(unsigned char obj_index)
{
    switch (obj_index)
    {
    case INDEX_CUBE:
        return obj_cube.triangle_counts;
    case INDEX_SPHERE:
        return obj_sphere.triangle_counts;
    case INDEX_CONE:
        return obj_cone.triangle_counts;
    case INDEX_BUNNY:
        return obj_bunny.triangle_counts;
    case INDEX_SMALLBUNNY:
        return obj_small_bunny.triangle_counts;
    case INDEX_FACE:
        return obj_face.triangle_counts;
    default:
        break;
    }
    return 0;
}

Vector3f *get_vertex_pos(unsigned char obj_index)
{
    switch (obj_index)
    {
    case INDEX_CUBE:
        return obj_cube.vertex_pos;
    case INDEX_SPHERE:
        return obj_sphere.vertex_pos;
    case INDEX_CONE:
        return obj_cone.vertex_pos;
    case INDEX_BUNNY:
        return obj_bunny.vertex_pos;
    case INDEX_SMALLBUNNY:
        return obj_small_bunny.vertex_pos;
    case INDEX_FACE:
        return obj_face.vertex_pos;
    default:
        break;
    }
    return 0;
}

Vector3i *get_indices(unsigned char obj_index)
{
    switch (obj_index)
    {
    case INDEX_CUBE:
        return obj_cube.indices;
    case INDEX_SPHERE:
        return obj_sphere.indices;
    case INDEX_CONE:
        return obj_cone.indices;
    case INDEX_BUNNY:
        return obj_bunny.indices;
    case INDEX_SMALLBUNNY:
        return obj_small_bunny.indices;
    case INDEX_FACE:
        return obj_face.indices;
    default:
        break;
    }
    return 0;
}