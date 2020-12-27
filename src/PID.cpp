#include "PID.h"

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */
  Kp = Kp_;
  Ki = Ki_;
  Kd = Kd_;
  prev_cte = 0.7598; // Initial CTE
  p_error = i_error = d_error = 0;
}

void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */

  p_error = cte;
  i_error += cte;
  d_error = cte - prev_cte;
  prev_cte = cte;
}

double PID::TotalError() {
  /**
   * TODO: Calculate and return the total error
   */
  total_error = p_error + i_error + d_error;
  return total_error;  // TODO: Add your total error calc here!
}

double PID::CalculateSteerValue() {
  double steer_value = -p_error*Kp - i_error*Ki - d_error*Kd;

  if (steer_value > 1.0) {
    steer_value = 1.0;
  }
  else if (steer_value < -1.0) {
    steer_value = -1.0;
  }

  return steer_value;
}