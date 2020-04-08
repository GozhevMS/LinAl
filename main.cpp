#include <iostream>

using namespace std;

class Vector3D{
private:
double x, y, z;
public:
    Vector3D(double x, double y, double z): x(x), y(y), z(z){}
    Vector3D():Vector3D(0, 0, 0){}

    ~Vector3D(){}

    double getX() const{return x;}
    double getY() const{return y;}
    double getZ() const{return z;}

    void setX(double x){this->x = x;}
    void setY(double y){this->y = y;}
    void setZ(double z){this->z = z;}


    Vector3D operator+ (const Vector3D& v2) const{
        return Vector3D(x+v2.x, y+v2.y, z+v2.z);
    }

    Vector3D operator- (const Vector3D& v2) const{
        return Vector3D(x-v2.x, y-v2.y, z-v2.z);
    }

    Vector3D operator* (const double a) const{
        return Vector3D(x*a, y*a, z*a);
    }
};

double operator* (const Vector3D& v1, const Vector3D& v2){
    return v1.getX()*v2.getX() + v1.getY()*v2.getY() + v1.getZ()*v2.getZ();
}

Vector3D operator* (double a, const Vector3D& v){
    return Vector3D(a*v.getX(), a*v.getY(), a*v.getZ());
}


istream& operator>>(istream &is, Vector3D &v){
    double x, y, z;
    is >> x >> y >> z;
    v.setX(x);
    v.setY(y);
    v.setZ(z);
    return is;
}

std::ostream& operator<<(std::ostream& os, const Vector3D& v){
    os << "(" << v.getX() << "; " << v.getY() << "; " << v.getZ() << ")";
    return os;
}

class Matrix3D{
private:
Vector3D x, y, z;
public:
    Matrix3D(Vector3D x, Vector3D y, Vector3D z): x(x), y(y), z(z){}
    Matrix3D(double x1, double x2, double x3, double y1, double y2, double y3, double z1, double z2, double z3): x(x1, x2, x3), y(y1, y2, y3), z(z1, z2, z3){}
    Matrix3D():Matrix3D(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0){}

    ~Matrix3D(){}

    Vector3D getX() const{return x;}
    Vector3D getY() const{return y;}
    Vector3D getZ() const{return z;}

    void setX(Vector3D x){this->x = x;}
    void setY(Vector3D y){this->y = y;}
    void setZ(Vector3D z){this->z = z;}


    Matrix3D operator+ (const Matrix3D& v2) const{
        return Matrix3D(x+v2.x, y+v2.y, z+v2.z);
    }

    Matrix3D operator- (const Matrix3D& v2) const{
        return Matrix3D(x-v2.x, y-v2.y, z-v2.z);
    }

    Matrix3D operator* (const double a) const{
        return Matrix3D(x*a, y*a, z*a);
    }
    double det(){
        return x.getX()*y.getY()*z.getZ()+x.getY()*y.getZ()*z.getX()+x.getZ()*y.getX()*z.getY()-x.getZ()*y.getY()*z.getX()-x.getX()*y.getZ()*z.getY()-x.getY()*y.getX()*z.getZ();
    }
};

Matrix3D operator* (const Matrix3D& v2, const Matrix3D& v1){
    Vector3D x1(v1.getX().getX(), v1.getY().getX(), v1.getZ().getX());
    Vector3D y1(v1.getX().getY(), v1.getY().getY(), v1.getZ().getY());
    Vector3D z1(v1.getX().getZ(), v1.getY().getZ(), v1.getZ().getZ());
    Vector3D x(x1*v2.getX(), y1*v2.getX(), z1*v2.getX());
    Vector3D y(x1*v2.getY(), y1*v2.getY(), z1*v2.getY());
    Vector3D z(x1*v2.getZ(), y1*v2.getZ(), z1*v2.getZ());

    return Matrix3D(x, y, z);
}

Vector3D operator* (const Matrix3D& v1, const Vector3D& v2){
    return Vector3D(v1.getX()*v2, v1.getY()*v2, v1.getZ()*v2);
}

Matrix3D operator* (double a, const Matrix3D& v){
    return Matrix3D(a*v.getX(), a*v.getY(), a*v.getZ());
}


istream& operator>>(istream &is, Matrix3D &v){
    Vector3D x, y, z;
    is >> x >> y >> z;
    v.setX(x);
    v.setY(y);
    v.setZ(z);
    return is;
}

std::ostream& operator<<(std::ostream& os, const Matrix3D& v){
    os << endl << v.getX() <<endl << v.getY() << endl << v.getZ() << endl;
    return os;
}


int main()
{
    Vector3D A(1, 2, 3);
    Vector3D B;
    cin >> B;

    cout << "A = " << A << endl;
    cout << "B = " << B << endl;
    cout << "A * 3 = " << A * 3 << endl;
    cout << "2 * B = " << 2 * B << endl;
    cout << "A + B = " << A + B << endl;
    cout << "A - B = " << A - B << endl;
    cout << "A * B = " << A * B << endl;

    Matrix3D C(1, 0, 0, 0, 1, 0, 0, 0, 1);
    Matrix3D D;
    cin >> D;

    cout << "C = " << C << endl;
    cout << "D = " << D << endl;
    cout << "C * 3 = " << C * 3 << endl;
    cout << "2 * D = " << 2 * D << endl;
    cout << "C + D = " << C + D << endl;
    cout << "C - D = " << C - D << endl;
    cout << "C * D = " << C * D << endl;

    cout << "det(D) = " << D.det() << endl;

    cout << "D * B = " << D * B << endl;

    return 0;
};
