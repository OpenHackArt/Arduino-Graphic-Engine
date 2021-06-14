#include "math.h"
#include "trigonometric.h"

// #define ACC

Matrix4f mMultiply(const Matrix4f mat1, const Matrix4f mat2)
{
    Matrix4f mat;
    for (unsigned char r = 0; r < 4; r++)
    {
        for (unsigned char c = 0; c < 4; c++)
        {
            mat.m[r][c] = mat1.m[r][0] * mat2.m[0][c] +
                          mat1.m[r][1] * mat2.m[1][c] +
                          mat1.m[r][2] * mat2.m[2][c] +
                          mat1.m[r][3] * mat2.m[3][c];
        }
    }
    return mat;
}

Matrix4f mRotateX(unsigned int angle)
{
    Matrix4f mat;
    angle = angle % 360;
    mat.m[1][1] = cos_value[angle];
    mat.m[1][2] = -sin_value[angle];
    mat.m[2][1] = sin_value[angle];
    mat.m[2][2] = cos_value[angle];
    return mat;
}

Matrix4f mRotateY(unsigned int angle)
{
    Matrix4f mat;
    angle = angle % 360;
    mat.m[0][0] = cos_value[angle];
    mat.m[0][2] = sin_value[angle];
    mat.m[2][0] = -sin_value[angle];
    mat.m[2][2] = cos_value[angle];
    return mat;
}

Matrix4f mRotateZ(unsigned int angle)
{
    Matrix4f mat;
    angle = angle % 360;
    mat.m[0][0] = cos_value[angle];
    mat.m[0][1] = -sin_value[angle];
    mat.m[1][0] = sin_value[angle];
    mat.m[1][1] = cos_value[angle];
    return mat;
}

Matrix4f mTranslate(const float x, const float y, const float z)
{
    Matrix4f mat;
    mat.m[0][3] = x;
    mat.m[1][3] = y;
    mat.m[2][3] = z;
    return mat;
}

Matrix4f mScale(const float ratio)
{
    Matrix4f mat;
    mat.m[0][0] = ratio;
    mat.m[1][1] = ratio;
    mat.m[2][2] = ratio;
    return mat;
}

Vector4f m4_mul_v3(const Matrix4f m, const Vector3f v)
{
    Vector4f v_res = v3tov4(v);
    v_res.x = m.m[0][0] * v_res.x + m.m[0][1] * v_res.y + m.m[0][2] * v_res.z + m.m[0][3] * v_res.w;
    v_res.y = m.m[1][0] * v_res.x + m.m[1][1] * v_res.y + m.m[1][2] * v_res.z + m.m[1][3] * v_res.w;
    v_res.z = m.m[2][0] * v_res.x + m.m[2][1] * v_res.y + m.m[2][2] * v_res.z + m.m[2][3] * v_res.w;
    v_res.w = m.m[3][0] * v_res.x + m.m[3][1] * v_res.y + m.m[3][2] * v_res.z + m.m[3][3] * v_res.w;
    return v_res;
}

Vector3f m_mul_v_acc(const Matrix4f m, const Vector3f v)
{
    Vector3f res;
    res.x = m.m[0][0] * v.x + m.m[1][0] * v.y + m.m[2][0] * v.z + m.m[3][0];
    res.y = m.m[0][1] * v.x + m.m[1][1] * v.y + m.m[2][1] * v.z + m.m[3][1];
    res.z = m.m[0][2] * v.x + m.m[1][2] * v.y + m.m[2][2] * v.z + m.m[3][2];
    return res;
}

Vector4f v3tov4(const Vector3f v3)
{
    Vector4f v;
    v.x = v3.x;
    v.y = v3.y;
    v.z = v3.z;
    v.w = 1;
    return v;
}

#ifdef ACC
bool is_hidden(const Vector2f v0, const Vector2f v1, const Vector2f v2)
{
    // shoelace algorithm to get triangle area
    return (v2.x - v0.x) * (v1.y - v0.y) < ((v1.x - v0.x) * (v2.y - v0.y));
}
#else
bool is_hidden(const Vector2f v0, const Vector2f v1, const Vector2f v2)
{
    // shoelace algorithm to get triangle area
    return (v0.x * v1.y - v1.x * v0.y) + (v1.x * v2.y - v2.x * v1.y) + (v2.x * v0.y - v0.x * v2.y) < 0 ? false : true;
}
#endif

// [inclusive, exclusive)
bool is_vertices_equal(int start, int end, Vector2f *buffer0, Vector2f *buffer1)
{
    for (int i = start; i < end; i++)
    {
        if (buffer0[i].x != buffer1[i].x)
            return false;
        if (buffer0[i].y != buffer1[i].y)
            return false;
    }
    return true;
}

// [inclusive, exclusive)
void copy_vertices(int start, int end, Vector2f *target, Vector2f *source)
{
    for (int i = start; i < end; i++)
    {
        target[i].x = source[i].x;
        target[i].y = source[i].y;
    }
}