#include "PID.h"
#include <algorithm>
/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */
  // p controller is the main part
  // i increases when the error keeps existing time. can lead to instability
  // d not important
  // start with proportional
  // add small integral
  // add derivative to help to anticipate turns
  // tune longitudinal in straight line
  // initialize error to 0 
  // initialize pid by setting inputs
  p_error = 0;
  i_error = 0;
  d_error = 0;
  Ki = Ki_;
  Kd = Kd_;
  Kp = Kp_;
}

void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */
  // update the derivative error: cte - p
  // update the  p error: cte
  // update integral: i_error + cte
  d_error = cte - p_error;
  p_error = cte;
  i_error += cte;
}

double PID::TotalError() {
  /**
   * TODO: Calculate and return the total error
   */
  // weighted sum  p_error * Kp + i_error * Ki + 
  return Kp*p_error + Ki * i_error + Kd + d_error;  // TODO: Add your total error calc here!
}