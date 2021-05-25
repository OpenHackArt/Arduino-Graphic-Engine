#ifndef MATH_H
#define MATH_H

#include "data_structure.h"

#define PI 3.1415926

Matrix4f mMultiply(const Matrix4f mat1, const Matrix4f mat2);

Matrix4f mRotateX(unsigned int angle);

Matrix4f mRotateY(unsigned int angle);

Matrix4f mRotateZ(unsigned int angle);

Matrix4f mTranslate(const float x, const float y, const float z);

Matrix4f mScale(const float ratio);

Vector3f m_mul_v(const Matrix4f m, const Vector3f v);

#endif