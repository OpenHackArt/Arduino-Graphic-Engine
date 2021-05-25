#include "data_structure.h"
#include "trigonometric.h"

#define PI 3.1415926

Matrix4f mMultiply(const Matrix4f &mat1, const Matrix4f &mat2)
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