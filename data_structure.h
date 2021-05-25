#ifndef DATA_STRUCTURE_H
#define DATA_STRUCTURE_H

typedef struct
{
    float x, y, z;
} Vector3f;

typedef struct
{
    float m[4][4] = {
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}};
} Matrix4f;

#endif // !DATA_STRUCTURE_H
