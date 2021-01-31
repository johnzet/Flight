#ifndef QUATERNION_H
#define QUATERNION_H

class Quaternion {
    private:

    protected:

    public:
        Quaternion();
        Quaternion(const Quaternion& q);
        Quaternion(const float real, const float x, const float y, const float z);
        Quaternion(const float real, const Vector& imaginary);
        Quaternion(const float eulerX, const float eulerY, const float eulerZ);
        float r, x, y, z;
        Vector* getNewEuler() const;
        Quaternion operator*(const Quaternion& rhs);
        Quaternion operator*(const float& rhs);
        Quaternion operator/(const float& rhs);
        Quaternion conj();
        float norm();
        void normalize();
        void getMatrix(float matrix[3][3]); // 3x3 matrix passed as pointer, * normalizes this *
        Vector* getNewSandwich(const Vector* v);  // rotate the vector by this quaternion
        Quaternion* getNewSlerp(const Quaternion* q2, float t);  // rotate this quaternion by the given quaternion a portion of the way
};

#endif
