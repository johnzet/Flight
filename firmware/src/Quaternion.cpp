#include <math.h>
#include <Vector.h>
#include <Quaternion.h>

const float PI = 3.1415926535f; 


Quaternion::Quaternion() {
    r = 1.0;
    x = y = z = 0.0;   
}

Quaternion::Quaternion(const Quaternion& q) {
    r = q.r;
    x = q.x;
    y = q.y;
    z = q.z;
}

Quaternion::Quaternion(const float real, const float ix, const float iy, const float iz) {
    r = real;
    x = ix;
    y = iy;
    z = iz;
}

Quaternion::Quaternion(const float real, const Vector& imaginary) {
    r = real;
    x = imaginary.x;
    y = imaginary.y;
    z = imaginary.z;
}

Quaternion::Quaternion(const float eulerX, const float eulerY, const float eulerZ) {
    // Expensive call (370 cycles optimized)

    float sinx = sinf(eulerX/2.0f);
    float siny = sinf(eulerY/2.0f);
    float sinz = sinf(eulerZ/2.0f);
    float cosx = cosf(eulerX/2.0f);
    float cosy = cosf(eulerY/2.0f);
    float cosz = cosf(eulerZ/2.0f);

    r = cosx*cosy*cosz + sinx*siny*sinz;
    x = sinx*cosy*cosz - cosx*siny*sinz;
    y = cosx*siny*cosz + sinx*cosy*sinz;
    z = cosx*cosy*sinz - sinx*siny*cosz;


    q = [ cang(:,1).*cang(:,2).*cang(:,3) - sang(:,1).*sang(:,2).*sang(:,3), ...
            cang(:,1).*sang(:,2).*sang(:,3) + sang(:,1).*cang(:,2).*cang(:,3), ...
            cang(:,1).*sang(:,2).*cang(:,3) - sang(:,1).*cang(:,2).*sang(:,3), ...
            cang(:,1).*cang(:,2).*sang(:,3) + sang(:,1).*sang(:,2).*cang(:,3)];
}

Vector* Quaternion::getNewEuler() const {

    float sqr = r*r;
    float sqx = x*x;
    float sqy = y*y;
    float sqz = z*z;

    // If quaternion is normalised the unit is one, otherwise it is the correction factor
    float unit = sqx + sqy + sqz + sqr;
    float test = r*y + x*z;
    float ex, ey, ez;

    if (test > 0.4999f * unit)
    {
        // pitch down gimbal lock
        ex = 0.0;
        ey = PI * 0.5f;
        ez = 2.0 * atan2(x, r);
    }
    else if (test < -0.4999f * unit)
    {
        // pitch up gimbal lock
        ex = 0.0;
        ey = -PI * 0.5f;
        ez = -2.0f * atan2f(x, r);
    }
    else
    {
        ex = atan2f(2.0f * (r*x + y*z), 1.0f-2.0f*(sqx+sqy));
        ey = asinf(2.0f * (r*y-z*x));
        ez = atan2f(2.0f * (r*z + x*y),  1.0f-2.0f*(sqy+sqz));
    }
    if (ex < 0.0f) ex += 2.0f*PI;
    if (ey < 0.0f) ey += 2.0f*PI;
    if (ez < 0.0f) ez += 2.0f*PI;

    return new Vector(ex, ey, ez);
}

Quaternion Quaternion::operator*(const Quaternion& rhs) {
    float q1r = r;
    float q1x = x;
    float q1y = y;
    float q1z = z;

    float q2r = rhs.r;
    float q2x = rhs.x;
    float q2y = rhs.y;
    float q2z = rhs.z;

    float ix = q1r*q2x + q1y*q2z - q1z*q2y + q1x*q2r;
    float iy = q1r*q2y + q1y*q2r + q1z*q2x - q1x*q2z;
    float iz = q1r*q2z - q1y*q2x + q1z*q2r + q1x*q2y;
    float r  = q1r*q2r - q1y*q2y - q1z*q2z - q1x*q2x;
    
    return Quaternion(r, ix, iy, iz);
}

Quaternion Quaternion::operator*(const float& rhs) {
    return Quaternion(r*rhs, x*rhs, y*rhs, z*rhs);
}

Quaternion Quaternion::operator/(const float& rhs) {
    return Quaternion(r/rhs, x/rhs, y/rhs, z/rhs);
}

Quaternion Quaternion::conj() {
    return Quaternion(r, -x, -y, -z);
}

float Quaternion::norm() {
    return sqrtf(r*r + x*x + y*y + z*z);
}

void Quaternion::normalize() {
    float n = norm();
    if (n == 0.0f) {
        r = x = y = z = 0.0f;
    } else {
        r /= n;
        x /= n;
        y /= n;
        z /= n;
    }
}

void Quaternion::getMatrix(float matrix[3][3]) {
    float sqrx = x*x;
    float sqry = y*y;
    float sqrz = z*z;
    matrix[0][0] = 1.0f - 2.0f*sqry - 2.0f*sqrz;
    matrix[1][0] = 2.0f*x*y - 2.0f*z*r;
    matrix[2][0] = 2.0f*x*z + 2.0f*y*r;
    matrix[0][1] = 2.0f*x*y + 2.0f*z*r;
    matrix[1][1] = 1.0f - 2.0f*sqrx - 2.0f*sqrz;
    matrix[2][1] = 2.0f*y*z - 2.0f*x*r;
    matrix[0][2] = 2.0f*x*z - 2.0f*y*r;
    matrix[1][2] = 2.0f*y*z + 2.0f*x*r;
    matrix[2][2] = 1.0f - 2.0f*sqrx - 2.0f*sqry;
}

Vector* Quaternion::getNewSandwich(const Vector* v) {
    normalize();        //    <------------ SIDE EFFECT
    Quaternion vq = Quaternion(0, *v);
    Quaternion q2 = (*this * vq) * conj();
    return new Vector(q2.x, q2.y, q2.z);
}

// Copied from http://www.euclideanspace.com/maths/algebra/realNormedAlgebra/quaternions/slerp/
Quaternion* Quaternion::getNewSlerp(const Quaternion* qb, float t) {
	// quaternion to return
	Quaternion* qm = new Quaternion();
	// Calculate angle between them.
	float cosHalfTheta = this->r * qb->r + this->x * qb->x + this->y * qb->y + this->z * qb->z;
	// if this=qb or this=-qb then theta = 0 and we can return this
	if (fabs(cosHalfTheta) >= 1.0) {
		qm->r = this->r;qm->x = this->x;qm->y = this->y;qm->z = this->z;
		return qm;
	}
	// Calculate temporary values.
	float halfTheta = acosf(cosHalfTheta);
	float sinHalfTheta = sqrtf(1.0f - cosHalfTheta*cosHalfTheta);
	// if theta = 180 degrees then result is not fully defined
	// we could rotate around any axis normal to this or qb
	if (fabsf(sinHalfTheta) < 0.001f) {
		qm->r = (this->r * 0.5f + qb->r * 0.5f);
		qm->x = (this->x * 0.5f + qb->x * 0.5f);
		qm->y = (this->y * 0.5f + qb->y * 0.5f);
		qm->z = (this->z * 0.5f + qb->z * 0.5f);
		return qm;
	}
	float ratioA = sinf((1 - t) * halfTheta) / sinHalfTheta;
	float ratioB = sinf(t * halfTheta) / sinHalfTheta; 
	//calculate Quaternion.
	qm->r = (this->r * ratioA + qb->r * ratioB);
	qm->x = (this->x * ratioA + qb->x * ratioB);
	qm->y = (this->y * ratioA + qb->y * ratioB);
	qm->z = (this->z * ratioA + qb->z * ratioB);
	return qm;
}

