#include "Vector3D.h"
Vector3D::Vector3D()
{
	/*x = 0;
	y = 0;
	z = 0;*/
}

Vector3D::Vector3D(double x, double y, double z)
{
	Vector3D::x = x;
	Vector3D::y = y;
	Vector3D::z = z;
}

Vector3D::~Vector3D()
{
}

double Vector3D::getX() const
{
	return Vector3D::x;
}

double Vector3D::getY() const
{
	return Vector3D::y;
}

double Vector3D::getZ() const
{
	return Vector3D::z;
}

void Vector3D::setX(double x)
{
	Vector3D::x = x;
}

void Vector3D::setY(double y)
{
	Vector3D::y = y;
}

void Vector3D::setZ(double z)
{
	Vector3D::z = z;
}

Vector3D Vector3D::operator+(const Vector3D& v2) const
{
	return Vector3D(x + v2.getX(), y + v2.getY(), z + v2.getZ());
}

Vector3D Vector3D::operator-(const Vector3D& v2) const
{
	return Vector3D(x - v2.getX(), y - v2.getY(), z - v2.getZ());
}

Vector3D Vector3D::operator*(const double a) const
{
	return Vector3D(x*a, y*a, z*a);
}

double operator*(const Vector3D& v1, const Vector3D& v2)
{
	return 	 v1.getX() * v2.getX() + v1.getY() * v2.getY() + v1.getZ() * v2.getZ();
}

Vector3D operator*(double a, const Vector3D& v)
{
	return Vector3D(v.getX() * a, v.getY() * a, v.getZ() * a);
}

std::istream& operator>>(std::istream& is, Vector3D& v) {
	double x, y, z;
	is >> x >> y >> z;
	v.setX(x);
	v.setY(y);
	v.setZ(z);
	return is;
}

std::ostream& operator<<(std::ostream& os, const Vector3D& v) {
	os << "(" << v.getX() << "; " << v.getY() << "; " << v.getZ() << ")";
	return os;
}
