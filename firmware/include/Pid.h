#ifndef PID_H
#define PID_H
#include <arm_math.h>
#include <Config.h>

class Pid {
    private:
        float totalError;
        float previousError;
        PidConfig* config;

    public:
        float p,i,d;
        Pid(PidConfig* pidCOnfig);
        float calculate(float error);
};
#endif
