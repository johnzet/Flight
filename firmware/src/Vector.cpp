#include <Vector.h>

Vector::Vector() {
    x = 0.0;
    y = 0.0;
    z = 0.0;
}

Vector::Vector(float x_arg, float y_arg, float z_arg) {
    x = x_arg;
    y = y_arg;
    z = z_arg;
}

Vector::Vector(const Vector& v) {
    x = v.x;
    y = v.y;
    z = v.z;
}

Vector Vector::operator*(const float& rhs) const {
    return Vector(x*rhs, y*rhs, z*rhs);
}

Vector Vector::operator+(const Vector& rhs) const {
    return Vector(x+rhs.x, y+rhs.y, z+rhs.z);
}

Vector Vector::operator-(const Vector& rhs) const {
    return Vector(x-rhs.x, y-rhs.y, z-rhs.z);
}
