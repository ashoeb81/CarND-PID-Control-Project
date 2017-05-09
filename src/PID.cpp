#include "PID.h"
#include <iostream>

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
    this->Kp = Kp;
    this->Ki = Ki;
    this->Kd = Kd;
    i_error = 0;
    prev_error = 0;
}

void PID::UpdateError(double cte) {
    // Proportional error.
    p_error = cte;
    // Integral error
    i_error += cte;
    // Derivative error
    d_error = cte - prev_error;
    prev_error = cte;
}

double PID::TotalError() {
    return -Kp * p_error - Kd * d_error - Ki * i_error;
}