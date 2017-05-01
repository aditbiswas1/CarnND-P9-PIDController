#include "PID.h"
#include <iostream>

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
    _Kp = Kp;
    _Ki = Ki;
    _Kd = Kd;
    i_error = 0;
    d_error = 0;
}

void PID::UpdateError(double cte) {
    d_error = cte;
    i_error += cte;
}

double PID::TotalError() {
}

double PID::CalculateControl(double cte){
    double control = -(_Kp * cte) - (_Kd * (cte - d_error)) - (_Ki * i_error);
    UpdateError(cte);
    return control;
}