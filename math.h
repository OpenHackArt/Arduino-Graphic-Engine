#ifndef MATH_H
#define MATH_H

#define PI 3.1415926

typedef struct
{
    int x, y, z;
} Vector3i;

typedef struct
{
    float x, y, z;
} Vector3f;

typedef struct
{
    float x, y;
} Vector2f;

typedef struct
{
    float m[4][4] = {
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}};
} Matrix4f;

Matrix4f mMultiply(const Matrix4f mat1, const Matrix4f mat2);

Matrix4f mRotateX(unsigned int angle);

Matrix4f mRotateY(unsigned int angle);

Matrix4f mRotateZ(unsigned int angle);

Matrix4f mTranslate(const float x, const float y, const float z);

Matrix4f mScale(const float ratio);

Vector3f m_mul_v(const Matrix4f m, const Vector3f v);

bool is_hidden(const Vector2f v0, const Vector2f v1, const Vector2f v2);

bool is_vertices_equal(int vertex_cnt, Vector2f *buffer0, Vector2f *buffer1);

void copy_vertices(int vertex_cnt, Vector2f *target, Vector2f *source);

#endif