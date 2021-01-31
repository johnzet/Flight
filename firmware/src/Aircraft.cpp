#include <Aircraft.h>

Aircraft::Aircraft(SensorTask* sensorTask, PwmCapture* pwmCapture, PwmGen* pwmGen) {
    this->sensorTask = sensorTask;
    this->pwmCapture = pwmCapture;
    this->pwmGen = pwmGen;
}

