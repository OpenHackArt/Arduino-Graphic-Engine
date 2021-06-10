#include "math.h"
#include "trigonometric.h"

Matrix4f mMultiply(const Matrix4f mat1, const Matrix4f mat2)
{
    Matrix4f mat;
    for (unsigned char c = 0; c < 4; c++)
    {
        for (unsigned char r = 0; r < 4; r++)
        {
            mat.m[c][r] = mat1.m[0][r] * mat2.m[c][0] +
                          mat1.m[1][r] * mat2.m[c][1] +
                          mat1.m[2][r] * mat2.m[c][2] +
                          mat1.m[3][r] * mat2.m[c][3];
        }
    }

    return mat;
}

Matrix4f mRotateX(unsigned int angle)
{
    Matrix4f mat;
    angle = angle % 360;
    mat.m[1][1] = cos_value[angle];
    mat.m[1][2] = sin_value[angle];
    mat.m[2][1] = -sin_value[angle];
    mat.m[2][2] = cos_value[angle];
    return mat;
}

Matrix4f mRotateY(unsigned int angle)
{
    Matrix4f mat;
    angle = angle % 360;
    mat.m[0][0] = cos_value[angle];
    mat.m[0][2] = -sin_value[angle];
    mat.m[2][0] = sin_value[angle];
    mat.m[2][2] = cos_value[angle];
    return mat;
}

Matrix4f mRotateZ(unsigned int angle)
{
    Matrix4f mat;
    angle = angle % 360;
    mat.m[0][0] = cos_value[angle];
    mat.m[0][1] = sin_value[angle];
    mat.m[1][0] = -sin_value[angle];
    mat.m[1][1] = cos_value[angle];
    return mat;
}

Matrix4f mTranslate(const float x, const float y, const float z)
{
    Matrix4f mat;
    mat.m[3][0] = x;
    mat.m[3][1] = y;
    mat.m[3][2] = z;
    return mat;
}

Matrix4f mScale(const float ratio)
{
    Matrix4f mat;
    mat.m[0][0] *= ratio;
    mat.m[1][1] *= ratio;
    mat.m[2][2] *= ratio;
    return mat;
}

Vector3f m_mul_v(const Matrix4f m, const Vector3f v)
{
    Vector3f v_res;
    v_res.x = m.m[0][0] * v.x + m.m[1][0] * v.y + m.m[2][0] * v.z + m.m[3][0];
    v_res.y = m.m[0][1] * v.x + m.m[1][1] * v.y + m.m[2][1] * v.z + m.m[3][1];
    v_res.z = m.m[0][2] * v.x + m.m[1][2] * v.y + m.m[2][2] * v.z + m.m[3][2];
    return v_res;
}

// bool is_hidden(const Vector2f v0, const Vector2f v1, const Vector2f v2)
// {
//     // shoelace algorithm to get triangle area
//     return (v2.x - v0.x) * (v1.y - v0.y) < ((v1.x - v0.x) * (v2.y - v0.y));
// }

bool is_hidden(const Vector2f v0, const Vector2f v1, const Vector2f v2)
{
    // shoelace algorithm to get triangle area
    return (v0.x * v1.y - v1.x * v0.y) + (v1.x * v2.y - v2.x * v1.y) + (v2.x * v0.y - v0.x * v2.y) < 0 ? false : true;
}

bool is_vertices_equal(int vertex_cnt, Vector2f *buffer0, Vector2f *buffer1)
{
    for (int i = 0; i < vertex_cnt; i++)
    {
        if (buffer0[i].x != buffer1[i].x)
            return false;
        if (buffer0[i].y != buffer1[i].y)
            return false;
    }
    return true;
}

void copy_vertices(int vertex_cnt, Vector2f *target, Vector2f *source)
{
    for (int i = 0; i < vertex_cnt; i++)
    {
        target[i].x = source[i].x;
        target[i].y = source[i].y;
    }
}