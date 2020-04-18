#include "Matrix3D.h"
Matrix3D::Matrix3D(Vector3D x, Vector3D y, Vector3D z) : x(x), y(y), z(z)
{
}

Matrix3D::Matrix3D(double x1, double x2, double x3, double y1, double y2, double y3, double z1, double z2, double z3) : x(x1, x2, x3), y(y1, y2, y3), z(z1, z2, z3)
{
}

Matrix3D::Matrix3D()
{
}

Matrix3D::~Matrix3D()
{
}

Vector3D Matrix3D::getX() const
{
	return x;
}

Vector3D Matrix3D::getY() const
{
	return y;
}

Vector3D Matrix3D::getZ() const
{
	return z;
}

void Matrix3D::setX(Vector3D x)
{
	Matrix3D::x = x;
}

void Matrix3D::setY(Vector3D y)
{
	Matrix3D::y = y;
}

void Matrix3D::setZ(Vector3D z)
{
	Matrix3D::z = z;
}

Matrix3D Matrix3D::operator+(const Matrix3D& v2) const
{
	return Matrix3D(x + v2.x, y + v2.y, z + v2.z);
}

Matrix3D Matrix3D::operator-(const Matrix3D& v2) const
{
	return Matrix3D(x - v2.x, y - v2.y, z - v2.z);
}

Matrix3D Matrix3D::operator*(const double a) const
{
	return Matrix3D(x * a, y * a, z * a);
}

double Matrix3D::det()
{
	return x.getX() * y.getY() * z.getZ() + x.getY() * y.getZ() * z.getX() + x.getZ() * y.getX() * z.getY() - x.getZ() * y.getY() * z.getX() - x.getX() * y.getZ() * z.getY() - x.getY() * y.getX() * z.getZ();
}

Matrix3D operator*(const Matrix3D& v2, const Matrix3D& v1)
{
	Vector3D x1(v1.getX().getX(), v1.getY().getX(), v1.getZ().getX());
	Vector3D y1(v1.getX().getY(), v1.getY().getY(), v1.getZ().getY());
	Vector3D z1(v1.getX().getZ(), v1.getY().getZ(), v1.getZ().getZ());
	Vector3D x(x1 * v2.getX(), y1 * v2.getX(), z1 * v2.getX());
	Vector3D y(x1 * v2.getY(), y1 * v2.getY(), z1 * v2.getY());
	Vector3D z(x1 * v2.getZ(), y1 * v2.getZ(), z1 * v2.getZ());

	return Matrix3D(x, y, z);
}

Vector3D operator*(const Matrix3D& v1, const Vector3D& v2)
{
	return Vector3D(v1.getX() * v2, v1.getY() * v2, v1.getZ() * v2);
}

Matrix3D operator*(double a, const Matrix3D& v)
{
	return Matrix3D(a * v.getX(), a * v.getY(), a * v.getZ());
}

std::istream& operator>>(std::istream& is, Matrix3D& v)
{
	Vector3D x, y, z;
	is >> x >> y >> z;
	v.setX(x);
	v.setY(y);
	v.setZ(z);
	return is;
}

std::ostream& operator<<(std::ostream& os, const Matrix3D& v)
{
	os << std::endl << v.getX() << std::endl << v.getY() << std::endl << v.getZ() << std::endl;
	return os;
}
