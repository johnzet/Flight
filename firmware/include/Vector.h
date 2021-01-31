#ifndef VECTOR_H
#define VECTOR_H

class Vector {
    private:

    protected:

    public:
        Vector();
        Vector(const Vector& v);
        Vector(float x, float y, float z);
        float x, y, z;
        Vector operator*(const float& rhs) const;
        Vector operator+(const Vector& rhs) const;
        Vector operator-(const Vector& rhs) const;
};

#endif