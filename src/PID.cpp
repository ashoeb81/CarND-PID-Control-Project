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
    p_error = 0;
}

void PID::UpdateError(double cte) {
    d_error = cte - p_error;
    p_error = cte;
    i_error += cte;
}

double PID::TotalError() {
    double command = -Kp*p_error - Kd*d_error - Ki*i_error;
    if (command >= 1) {
        return 1;
    } else if (command <= -1) {
        return -1;
    } else {
        return command;
    }
}