#pragma once
#ifndef MATRIX3D_H
#define MATRIX3D_H
#include <iostream>
#include "Vector3D.h"

class Matrix3D {
private:
    Vector3D x, y, z;
public:
    Matrix3D(Vector3D x, Vector3D y, Vector3D z);
    Matrix3D(double x1, double x2, double x3, double y1, double y2, double y3, double z1, double z2, double z3);
    Matrix3D();

    ~Matrix3D();

    Vector3D getX() const;
    Vector3D getY() const;
    Vector3D getZ() const;

    void setX(Vector3D x);
    void setY(Vector3D y);
    void setZ(Vector3D z);


    Matrix3D operator+ (const Matrix3D& v2) const;

    Matrix3D operator- (const Matrix3D& v2) const;

    Matrix3D operator* (const double a) const;
    double det();
};

Matrix3D operator* (const Matrix3D& v2, const Matrix3D& v1);

Vector3D operator* (const Matrix3D& v1, const Vector3D& v2);

Matrix3D operator* (double a, const Matrix3D& v);


std::istream& operator>>(std::istream& is, Matrix3D& v);

std::ostream& operator<<(std::ostream& os, const Matrix3D& v);
#endif
