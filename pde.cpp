//
//  pde.cpp
//  fdm_vanilla_option
//
//  Created by Matthew liew on 14.11.23.
//

#include "pde.hpp"
#include <cmath>

BlackScholesPDE::BlackScholesPDE(VanillaOption* _option)
: option(_option) {}

// diffusion term
double BlackScholesPDE::diff_coeff(const double& S, const double& t) const {
    double vol = option->sigma;
    return 0.5 * vol * vol * S * S;
}

// Convection term
double BlackScholesPDE::conv_coeff(const double& S, const double& t) const {
  return (option->r)*S;  // rS
}

// Zero-term term
double BlackScholesPDE::zero_coeff(const double& S, const double& t) const {
  return -(option->r);  // -r
}

// Source term
double BlackScholesPDE::source_coeff(const double& S, const double& t) const {
  return 0.0;
}

// Initial condition (vanilla call option)
double BlackScholesPDE::init_cond(const double& S) const {
  return option->pay_off->operator()(S);
}

// Left boundary-condition (vanilla call option)
double BlackScholesPDE::boundary_left(const double& S, const double& t) const {
  return 0.0;  // Specifically for a CALL option
}

// Right boundary-condition (vanilla call option)
double BlackScholesPDE::boundary_right(const double& S, const double& t) const {
  // This is via Put-Call Parity and works for a call option
  return (S - (option->K)*exp(-(option->r)*((option->T)-t)));
}



