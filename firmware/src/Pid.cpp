#include <Pid.h>

Pid::Pid(PidConfig* pidConfig) {
    this->config = pidConfig;
    this->p = config->p;
    this->i = config->i;
    this->d = config->d;

    this->totalError = 0;
    this->previousError = 0;
}


float Pid::calculate(float error) {
    this->p = config->p;
    this->i = config->i;
    this->d = config->d;

    totalError += error;
    float _p = error * p;
    float _i = totalError * i;
    float _d = fabsf(error - previousError) * d;
    previousError = error;
    return _p + _i + _d;
}